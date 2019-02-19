#ifndef BSQ_H_
# define BSQ_H_

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_position
{
  int		i;
  int		count;
}		t_position;

typedef struct	s_carre
{
  int		k;
  int		b;
  int		save;
}		t_carre;

void		my_putchar(char c);
char		*open_file(const char *file);
int		verif_tab(char *buf);
int		my_strlen(char *str);
void		my_putstr(char *str);
int		my_getnbr(char *str);
int		nbr_line(char *str);
int		nbr_column(char *str);
int		isnum(char *str);
int		**double_tab(int x, int y);
void		free_tab(int **tab, char *str);
int		**fill_tab(char *str);
int		**put_zero(char *buf);
int		compare(int **tab, int x, int y);
int		**deminor(char *buf);
int		big(char *buf);
int		**put_one_x(int **tab, char *buf);
int		**funk(char *buf);
int		*final_cube(int **tab, char *buf);
int		**full_x(int **tab, char *buf);
int		*suite_tab(char *buf);
int		**complete_tab(int **tab, char *buf);
int		verif_tab(char *buf);
int		verif_map(char *buf);
int		my_verif_line(char *buf);
void		my_puterror(void);
int		count_tab(char *str);
char		*str_bsq(int **tab, char *str);

#endif /* !BSQ_H_ */
