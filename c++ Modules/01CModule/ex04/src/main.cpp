#include <iostream>
#include <fstream>
#include <string.h>

static void	replace(std::string & str, char *s1, char *s2)
{
	size_t index = 0;
	size_t s1Len = strlen(s1);
	size_t s2Len = strlen(s2);

	if (s1Len == 0)
		return ;
	while (1)
	{
		index = str.find(s1, index);
		if (index == std::string::npos)
			break ;
		str.erase(index, s1Len);
		str.insert(index, s2);
		index += s2Len;
	}
}

static int getString(char *arg, std::string & str)
{
	char			c;
	std::ifstream	in(arg);

	if (in.fail())
	{
		std::cerr << "Error opening file" << std::endl;
		return -1;
	}
	while (in.get(c))
	{
		str.push_back(c);
	}
	if (!in.eof())
	{
		std::cerr << "Error reading file" << std::endl;
		return -1;
	}
	return 0;
}

static int outputResult(char *arg, std::string & str)
{
	std::ofstream out((std::string(arg) + ".replace").c_str());

	if (out.fail())
	{
		std::cerr << "Error creating output file" << std::endl;
		return -1;
	}
	out << str;
	if (out.fail())
	{
		std::cerr << "Error writting result" << std::endl;
		return -1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	std::string str;

	if (argc != 4)
	{
		std::cerr << "./replace filename string1 string2" << std::endl;
		return (1);
	}
	if (getString(argv[1], str) == -1)
	{
		return (1);
	}
	replace(str, argv[2], argv[3]);
	if (outputResult(argv[1], str) == -1)
	{
		return (1);
	}
	return (0);
}
