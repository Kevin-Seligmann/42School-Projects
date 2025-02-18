cc -c -Wall -Wextra -Werror ft_putchar.c
cc -c -Wall -Wextra -Werror ft_swap.c
cc -c -Wall -Wextra -Werror ft_putstr.c
cc -c -Wall -Wextra -Werror ft_strlen.c
cc -c -Wall -Wextra -Werror ft_strcmp.c
ar -rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
rm ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
