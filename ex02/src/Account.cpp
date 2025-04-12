#include "Account.hpp"
#include <iostream>

Account::Account() {};

bool	Account::makeWithdrawal(int withdrawal) {
	if (this->_amount >= withdrawal)	
	{
		this->_amount -= withdrawal;
		return (true);
	}
	return (false);
}

void	Account::makeDeposit(int deposit) {
		this->_amount += deposit;
}

int	Account::checkAmount(void) const {
	std::cout << this->_amount;
}

void	Account::displayAccountsInfos(void) {
	for (int i = 0; i < getNbAccounts(); i++) {
		_displayTimestamp();
		std::cout << "index:" << i << ";";
		std::cout << "amount:" << checkAmount << ";";
		//  missing
		std::cout << std::endl;
	}
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
}

// void	Account::displayStatus( void ) const {
	
// }