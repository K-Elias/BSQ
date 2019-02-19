#include "bsq.h"

int	main(int ac, char **av)
{
  char	*str;
  int	**tab;
  char	*buf;

  if (ac == 2)
    {
      if ((str = open_file(av[1])) == NULL)
	return (1);
      tab = full_x(complete_tab(put_one_x(deminor(str), str), str), str);
      buf = str_bsq(tab, str);
      my_putstr(buf);
      free_tab(tab, str);
      free(str);
      free(buf);
    }
  else
    {
      my_putstr("ERROR: Only put the map on parameter please\n");
      return (-1);
    }
  return (0);
}
