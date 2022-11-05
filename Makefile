NAME	=	myshell
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

SRCS	= srcs/*.c
OBJS    = $(SRCS:.c=.o)
