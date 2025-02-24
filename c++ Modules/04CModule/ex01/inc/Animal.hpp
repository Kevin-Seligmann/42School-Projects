#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
	Animal(void);
	Animal(Animal const & src);
	virtual ~Animal(void);

	Animal & operator=(Animal const & rhs);

	std::string const & getType(void) const;
	void setType(std::string & type);

	virtual void makeSound(void) const;

protected:
	std::string _type;
};

#endif
