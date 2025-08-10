#ifndef FORDJOHNSON_HPP
#define FORDJOHNSON_HPP

#include <iostream>
#include <vector>
#include "Utils.hpp"

class FordJohnson {

	private:
		std::vector<int>	_main;
		std::vector<int>	_pend;
		std::vector<int>	_unused;

	public:
		FordJohnson();
		FordJohnson(const FordJohnson& other);
		~FordJohnson();

		FordJohnson&	operator=(const FordJohnson& other);

		std::vector<int>&	getMain(void);
		std::vector<int>	getMain(void) const;
		std::vector<int>&	getPend(void);
		std::vector<int>	getPend(void) const;
		std::vector<int>&	getUnused(void);
		std::vector<int>	getUnused(void) const;
};

std::ostream&	operator<<(std::ostream& out, const FordJohnson& obj);

#endif