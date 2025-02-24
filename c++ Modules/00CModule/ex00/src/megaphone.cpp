#include <iostream>
#include <string>

int main(int argc, char **argv){
	int	i = 1;
	int j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			argv[i][j] = std::toupper(argv[i][j]);
			j ++;
		}
		std::cout << argv[i];
		i ++;
	}
	std::cout << std::endl;
}
