#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(AAnimal const & src);
	virtual ~AAnimal(void);

	AAnimal & operator=(AAnimal const & rhs);

	std::string const & getType(void) const;
	void setType(std::string & type);

	virtual void makeSound(void) const = 0;

protected:
	std::string _type;
};

#endif
