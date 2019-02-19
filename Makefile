CC	= gcc

RM	= rm -rf

F	= src/

POINT_C	= $(F)open_file.c \
	  $(F)functions.c \
	  $(F)compt.c \
	  $(F)deminor.c \
	  $(F)final.c \
	  $(F)small.c \
	  $(F)my_puterror.c \
	  $(F)main.c

CFLAGS	+= -W -Wall -Wextra

CFLAGS	+= -I./include

OBJS	= $(POINT_C:.c=.o)

NAME	= bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
