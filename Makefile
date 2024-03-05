CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=pipex

LIBC=ar rcs

RM=rm -rf

SRCS = pipex.c utils.c libft/libft.a\

$(NAME):
		make all -C libft
		gcc $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

fclean: clean
		$(RM) $(NAME)
		make fclean -C libft

clean: $(RM) $(NAME)

re: fclean all


#CFILES := $(wildcard *.c)

#OBJECTS=$(CFILES:.c=.o)

#all:$(NAME)

#$(NAME):$(OBJECTS)
#	$(LIBC) $(NAME) $(OBJECTS)
#%.o:%.c
#	$(CC) $(CFLAGS) -c -o $@ $^
#clean:
#	$(RM) $(OBJECTS)
#fclean: clean
#	$(RM) $(NAME)
#re: fclean all
#.PHONY:	all clean fclean re
