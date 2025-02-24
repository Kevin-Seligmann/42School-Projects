#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	~MateriaSource(void);

	MateriaSource & operator=(MateriaSource const & rhs);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

private:
	static const int _MaxMateriaNumber = 4;
	AMateria	*_materias[_MaxMateriaNumber];
};

#endif
