#include "bsq.h"

int		big(char *buf)
{
  int		i;
  int		j;
  int		x;
  int		y;
  int		stock;
  int		**tab;

  i = -1;
  stock = 0;
  x = nbr_line(buf);
  y = nbr_column(buf);
  tab = deminor(buf);
  while (++i < x)
    {
      j = -1;
      while (++j < y)
	{
	  if (tab[i][j] > stock)
	    stock = tab[i][j];
	}
    }
  if (stock == 0)
    exit(1);
  return (stock);
}

int		**put_one_x(int **tab, char *buf)
{
  int		x;
  int		y;
  int		b;
  int		i;
  int		j;

  x = nbr_line(buf);
  y = nbr_column(buf);
  b = big(buf);
  i = -1;
  while (++i < x)
    {
      j = -1;
      while (++j < y)
	if (tab[i][j] == b)
	  {
	    tab[i][j] = 'x';
	    return (tab);
	  }
	else if (tab[i][j] == '0')
	  tab[i][j] = 'o';
	else
	  tab[i][j] = '.';
    }
  return (tab);
}

int	*suite_tab(char	*buf)
{
  int  	**tab;
  int	i;
  int	j;
  int	x;
  int	y;
  int	*dest;

  i = -1;
  x = nbr_line(buf);
  y = nbr_column(buf);
  tab = put_one_x(deminor(buf), buf);
  if (!(dest = malloc(sizeof(int *) * 1)))
    return (NULL);
  while (++i < x)
    {
      j = -1;
      while (++j < y)
	if (tab[i][j] == 'x')
	  {
	    dest[0] = i;
	    dest[1] = j;
	    return (dest);
	  }
    }
  return (dest);
}

int	**complete_tab(int **tab, char *buf)
{
  int	i;
  int	j;
  int	x;
  int	y;
  int	*dest;

  dest = suite_tab(buf);
  i = dest[0];
  j = dest[1] + 1;
  x = nbr_line(buf);
  y = nbr_column(buf);
  while (i < x)
    {
      while (j < y)
	{
	  if (tab[i][j] == '0')
	    tab[i][j] = 'o';
	  else
	    tab[i][j] = '.';
	  j++;
	}
      j = 0;
      i++;
    }
   return (tab);
}
