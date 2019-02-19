#include "bsq.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = my_strlen(str);
  write(1, str, i);
}

int		my_getnbr(char *str)
{
  unsigned int	a;
  int		b;
  int		i;

  a = 0;
  b = 1;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	b = -b;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      a = a * 10 + str[i] - '0';
      if ((a > 2147483647 && b > 0) || (a > 2147483648 && b < 0))
	return (0);
      i++;
    }
  return (a * b);
}

int	isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  i++;
  return (i);
}
