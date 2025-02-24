#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{

public:
	Harl(void);
	~Harl(void);

	void complain(std::string level);


private:
	static const int _levelCount = 4;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);


};

typedef void (Harl::*t_func)(void);

#endif
