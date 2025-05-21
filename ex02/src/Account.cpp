#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>


/****************************************************
*					CONSTRUCTORS					*
****************************************************/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {};

Account::Account(int initial_deposit) {

	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts++;
}

Account::~Account() {};

/****************************************************
*					STATIC FUNCTIONS				*
****************************************************/

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return(_totalAmount);
}

int	Account::getNbWithdrawals(void) {
	return(_totalNbWithdrawals);
}

int	Account::getNbDeposits(void) {
	return(_totalNbDeposits);
}

void	Account::_displayTimestamp(void) {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);
    std::cout << "[" << std::put_time(&now_tm, "%Y%m%d_%H%M%S") << "]" << std::endl;
}

/****************************************************
*				NON-STATIC FUNCTIONS				*
****************************************************/

bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
	return (false);
}

void	Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
}

// int	Account::checkAmount(void) const {
// 	std::cout << this->_amount;
// }

void	Account::displayAccountsInfos(void) {
	for (int i = 0; i < getNbAccounts(); i++) {
		_displayTimestamp();
		std::cout << "index:" <<  << ";";
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