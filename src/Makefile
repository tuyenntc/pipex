CC=gcc
CFLAGS=-Wall -Wextra -Werror -I../libft

NAME=pipex
SRC= pipex.c utils.c

LIBFT_DIR = ../libft
LIBFT= $(LIBFT_DIR)/libft.a
LIB= -L$(LIBFT_DIR) -lft
LDFLAGS=$(LIB)

OBJ=$(SRC:.c=.o)

LIBC=ar rcs
RM=rm -rf

all: $(NAME)

$(NAME):$(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)
	
fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

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
