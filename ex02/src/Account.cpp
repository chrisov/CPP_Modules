#include "Account.hpp"
#include <iostream>

Account::Account() {};

static int	getNbAccounts( void ) {
	return (8);
}
// bool	Account::makeWithdrawal(int withdrawal) {
// 	if (this->_amount >= withdrawal)	
// 	{
// 		this->_amount -= withdrawal;
// 		return (true);
// 	}
// 	return (false);
// }

// void	Account::makeDeposit(int deposit) {
// 		this->_amount += deposit;
// }

// int	Account::checkAmount(void) const {
// 	std::cout << this->_amount;
// }

void	Account::displayAccountsInfos(void) {
	for (int i = 0; i < getNbAccounts(); i++) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << getTotalAmount() << ";";
		//  missing
		std::cout << std::endl;
	}
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";";
}

// void	Account::displayStatus( void ) const {
	
// }