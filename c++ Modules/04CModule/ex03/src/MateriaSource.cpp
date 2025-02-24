#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < _MaxMateriaNumber; i++)
	{
		_materias[i] = NULL;
	}
	std::cout << "MateriaSource called with default constructor" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	for (int i = 0; i < _MaxMateriaNumber; i++)
	{
		if (src._materias[i])
			_materias[i] = src._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	std::cout << "MateriaSource called with copy constructor" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _MaxMateriaNumber; i++)
	{
		if (_materias[i])
		 delete _materias[i];
	}
	std::cout << "MateriaSource destroyed" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < _MaxMateriaNumber; i++)
		{
			if (rhs._materias[i])
				_materias[i] = rhs._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	std::cout << "Assignment called, MateriaSource" << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia)
	{
		for (int i = 0; i < _MaxMateriaNumber; i++)
		{
			if (_materias[i] == NULL)
			{
				_materias[i] = materia;
				std::cout << "Materia learned " << materia->getType() << std::endl;
				return ;
			}
		}
		delete materia;
	}
	std::cout << "Couldn't learn materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _MaxMateriaNumber && _materias[i]; i++)
	{
		if (_materias[i]->getType() == type)
		{
			return _materias[i]->clone();
		}
	}
	std::cout << "Materia source not found" << std::endl;
	return NULL;
}

