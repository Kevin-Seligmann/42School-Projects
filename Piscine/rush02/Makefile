source = main.c	rush-02.c find.c select_file.c ft_atoi.c ft_strlen.c ft_putnbr.c

flags = -Wall -Wextra -Werror

objs = $(source:.c=.o)

NAME = rush-02

$(NAME): $(objs)
	cc -o rush-02 $(objs)

main.o: main.c
	cc -c $(flags) main.c

rush-02.o: rush-02.c
	cc -c $(flags) rush-02.c

find.o: find.c
	cc -c $(flags) find.c

select_file.o: select_file.c
	cc -c $(flags) select_file.c

ft_atoi.o: ft_atoi.c
	cc -c $(flags) ft_atoi.c

ft_strlen.o: ft_strlen.c
	cc -c $(flags) ft_strlen.c

ft_putnbr.o: ft_putnbr.c
	cc -c $(flags) ft_putnbr.c

fclean: clean

.PHONY: clean

clean:
	rm -f  $(NAME) $(objs)
