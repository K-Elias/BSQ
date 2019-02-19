#include "bsq.h"

int		*final_cube(int **tab, char *buf)
{
  int		*dst;
  int		x;
  int		y;
  int		i;
  int		j;

  if (!(dst = malloc(sizeof(int *) * 1)))
    return (NULL);
  i = -1;
  x = nbr_line(buf);
  y = nbr_column(buf);
  while (++i < x)
    {
      j = -1;
      while (++j < y)
	{
	  if (tab[i][j] == 'x')
	    {
	      dst[0] = i;
	      dst[1] = j;
	    }
	}
    }
  return (dst);
}

int		**full_x(int **tab, char *buf)
{
  int	 	*dst;
  t_carre	cube;
  int		i;
  int		j;

  dst = final_cube(complete_tab(put_one_x(deminor(buf), buf), buf), buf);
  i = dst[0];
  j = dst[1];
  cube.k = -1;
  cube.b = big(buf);
  cube.save = cube.b - 48;
  while (++(cube.k) < cube.b - 48)
    {
      while (cube.save > 0)
	{
	  tab[i][j] = 'x';
	  cube.save = cube.save - 1;
	  j = j - 1;
	}
      cube.save = cube.b - 48;
      j = j + cube.save;
      i = i - 1;
    }
  free(dst);
  return (tab);
}

int		count_tab(char *str)
{
  int		i;
  int		j;
  int		x;
  int		y;
  int		count;

  i = 0;
  count = 0;
  x = nbr_line(str);
  y = nbr_column(str);
  while (i < x)
    {
      j = 0;
      while (j <= y)
	{
	  count++;
	  j++;
	}
      i++;
    }
  return (count);
}

char	*str_bsq(int **tab, char *buf)
{
  int	i;
  int	j;
  int	x;
  int	y;
  int	count;
  char	*str;

  i = -1;
  x = nbr_line(buf);
  y = nbr_column(buf);
  count = 0;
  if (!(str = malloc(sizeof(char *) * (count_tab(buf) + 1))))
    return (NULL);
  while (++i < x)
    {
      j = -1;
      while (++j <= y)
	{
	  str[count] = tab[i][j];
	  count++;
	}
    }
  str[count] = '\0';
  return (str);
}
