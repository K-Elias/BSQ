int	verif_tab(char *buf)
{
  int	i;

  i = 0;
  while (buf[i] != '\n')
    {
      if (buf[i] < '0' && buf[i] > '9')
	{
	  my_putstr("ERROR : bad map.\n");
	  return (-1);
	}
      i++;
    }
  return (0);
}

int	verif_map(char *buf)
{
  int	i;

  i = isnum(buf);
  while (buf[i] != '\0')
    {
      if (buf[i] != '.' && buf[i] != 'o' && buf[i] != '\n')
	return (-1);
      i++;
    }
  return (0);
}

int	my_verif_line(char *buf)
{
  int	i;
  int	line;
  int	count;

  i = isnum(buf);
  count = 0;
  line = nbr_line(buf);
  while (buf[i] != '\0')
    {
      if (buf[i] == '\n')
	count++;
      i++;
    }
  if (count != line)
    return (-1);
  return (0);
}

char		*open_file(const char *file)
{
  int		fd;
  int		red;
  char		*buf;
  struct stat	s;

  stat(file, &s);
  if (!(buf = malloc(sizeof(char *) * (s.st_size + 1))))
    return (NULL);
  if ((fd = open(file, O_RDONLY, S_IRUSR)) == -1)
    return (NULL);
  if ((red = read(fd, buf, (s.st_size + 1))) == -1)
    return (NULL);
  buf[red] = '\0';
  if (close(fd) == -1)
    return (NULL);
  if (verif_tab(buf) == -1)
    my_puterror();
  if (verif_map(buf) == -1)
    my_puterror();
  if (my_verif_line(buf) == -1)
    my_puterror();
  return (buf);
}
