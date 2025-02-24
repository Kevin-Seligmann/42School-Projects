#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal 
{
public:
	Cat(void);
	Cat(Cat const & src);
	~Cat(void);

	Cat & operator=(Cat const & rhs);

	void makeSound(void) const;
	void speakYourMind(unsigned int n) const;
	void setBrain(Brain brain);


private:
	Brain *_brain;
};

#endif
