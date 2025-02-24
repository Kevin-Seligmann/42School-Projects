#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain(void);
	Brain(Brain const & src);
	~Brain(void);

	Brain & operator=(Brain const & rhs);

	void setIdea(std::string const & idea, unsigned int n);

	std::string const & getIdea(unsigned int n) const;

private:
	std::string _ideas[100];
};

#endif
