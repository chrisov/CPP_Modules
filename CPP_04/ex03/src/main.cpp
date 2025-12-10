#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Abstracts/AMateria.hpp"

int main()
{
	std::cout << "\nv================== CONSTRUCTORS ==================v" << std::endl;
	IMateriaSource*	src = new MateriaSource();
	Ice*			ice = new Ice();
	Cure*			cure = new Cure();
	ICharacter*		me = new Character("me");
	AMateria*		tmp;
	std::cout << "^==================================================^\n" << std::endl;
	
	
	std::cout << "\nv================== MATERIASOURCE =================v" << std::endl;
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->getSource();
	std::cout << "^==================================================^\n" << std::endl;
	

	std::cout << "\nv=================== EQUIP MATERIA ================v" << std::endl;
	me->getInv();
	std::cout << std::endl;

	tmp = src->createMateria("ice");
	std::cout << "New '" << color(tmp->getType(), YLW) << "' Materia in address: " << tmp << '\n' << std::endl; 
	me->equip(tmp);
	std::cout << std::endl;

	tmp = src->createMateria("cure");
	std::cout << "New '" << color(tmp->getType(), YLW) << "' Materia in address: " << tmp << '\n' << std::endl; 
	me->equip(tmp);
	std::cout << std::endl;
	
	AMateria*	droppedMateria;
	droppedMateria = src->createMateria("ice");
	std::cout << "New '" << color(droppedMateria->getType(), YLW) << "' Materia in address: " << droppedMateria << '\n' << std::endl; 
	me->equip(droppedMateria);
	
	me->getInv();
	
	me->unequip(2);
	me->getInv();
	std::cout << "Dropped '" << color(droppedMateria->getType(), YLW) << "' Materia is still in address: " << droppedMateria << '\n' << std::endl;
	std::cout << "^==================================================^\n" << std::endl;
	
	
	std::cout << "\nv==================== CHARACTER ===================v" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "^==================================================^\n" << std::endl;
	
	
	std::cout << "\nv=================== DESTRUCTORS ==================v" << std::endl;
	delete src;
	delete ice;
	delete cure;
	delete bob;
	delete me;
	std::cout << "^==================================================^\n" << std::endl;
	return 0;
}