#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Interfaces/ICharacter.hpp"
#include "Abstracts/AMateria.hpp"


class Character : public ICharacter {
	
	private:
		std::string	_name;
		AMateria*	_inv[4];

	public:
		Character();
		Character(const Character& other);
		Character(const std::string& name);
		~Character();

		Character&	operator=(const Character& other);

		const std::string&	getName(void) const override;
		void				equip(AMateria* m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter& target) override;
		void				getInv(void) override;
};

#endif