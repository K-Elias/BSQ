#include "bsq.h"

int	**put_zero(char *buf)
{
  int	i;
  int	j;
  int	x;
  int	y;
  int	**tab;

  x = nbr_line(buf);
  y = nbr_column(buf);
  tab = fill_tab(buf);
  i = -1;
  while (++i < x)
    {
      j = 0;
      while (j < y)
	{
	  if (tab[i][j] == 'o')
	    tab[i][j] = '0';
	  if (tab[0][j] == '.')
	    tab[i][j] = '1';
	  if (tab[i][0] == '.')
	    tab[i][j] = '1';
	  j++;
	}
    }
  return (tab);
}

int		compare(int **tab, int x, int y)
{
  int		small;

  small = 2147483647;
  if (tab[x][y] == '0')
    return (48);
  if (tab[x][y - 1] < small)
    small = tab[x][y - 1];
  if (tab[x - 1][y] < small)
    small = tab[x - 1][y];
  if (tab[x - 1][y - 1] < small)
    small = tab[x - 1][y - 1];
  small = small + 1;
  return (small);
}

int		**deminor(char *buf)
{
  int		i;
  int		j;
  int		x;
  int		y;
  int		**tab;

  i = 1;
  x = nbr_line(buf);
  y = nbr_column(buf);
  tab = put_zero(buf);
  while (i < x)
    {
      j = 1;
      while (j < y)
	{
	  tab[i][j] = compare(tab, i, j);
	  j++;
	}
      i++;
    }
  return (tab);
}
