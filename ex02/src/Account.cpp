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
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
};

Account::~Account() {
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
};

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
    std::cout << "[" << std::put_time(&now_tm, "%Y%m%d_%H%M%S") << "] ";
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
}

/****************************************************
*				NON-STATIC FUNCTIONS				*
****************************************************/

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount" << _amount << ";";
	std::cout << "withdrawal:";
	if (checkAmount() >= withdrawal) {
		std::cout << withdrawal << ";";
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

int	Account::checkAmount(void) const {
	return (_amount);
}
