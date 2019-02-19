#include "bsq.h"

int	nbr_line(char *str)
{
  return (my_getnbr(str));
}

int	nbr_column(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = isnum(str);
  while (str[count] != '\n')
    {
      count++;
      i++;
    }
  return (i);
}

int	**double_tab(int x, int y)
{
  int	i;
  int	**tab;

  i = 0;
  if (!(tab = malloc(sizeof(int **) * x)))
    return (NULL);
  while (i < x)
    {
      if (!(tab[i] = malloc(sizeof(int *) * (y + 1))))
	return (NULL);
      i++;
    }
  return (tab);
}

void	free_tab(int **tab, char *str)
{
  int	i;
  int	x;

  i = 0;
  x = nbr_line(str);
  while (i < x)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

int		**fill_tab(char *str)
{
  int		i;
  int		x;
  int		y;
  int		**tab;

  i = isnum(str);
  x = 0;
  y = 0;
  tab = double_tab(nbr_line(str), nbr_column(str));
  while (str[i] != '\0')
    {
      tab[y][x] = str[i];
      x++;
      if (str[i] == '\n')
	{
	  y++;
	  x = 0;
	}
      i++;
    }
  return (tab);
}
