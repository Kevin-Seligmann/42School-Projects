#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog(void);
	Dog(Dog const & src);
	~Dog(void);

	Dog & operator=(Dog const & rhs);

	void makeSound(void) const;
	void speakYourMind(unsigned int n) const;
	void setBrain(Brain brain);

private:
	Brain* _brain;
};

#endif
