##
## EPITECH PROJECT, 2019
## make
## File description:
## file
##

SRC 	=	src/*.cpp

OBJ	=	$(SRC.cpp=.o)

NAME	=	autoCompletion

IFLAGS	=	-I./include

ERRORFLAGS	=	-I./error/

CFLAGS	=	-W -Werror -Wextra

all: $(NAME)

$(NAME): fclean
	g++ -o $(NAME) $(SRC) $(CLFAGS) $(IFLAGS) $(ERRORFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)

re: fclean all
