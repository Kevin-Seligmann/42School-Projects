#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors, destructors
Account::Account(int initial_deposit)
	: _accountIndex(Account::_nbAccounts)
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0){
	Account::_nbAccounts ++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::Account(void){}

Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

// Static functions
void Account::_displayTimestamp(void){
	time_t tt;
	struct tm* 	ptime;

	time(&tt);

	ptime = localtime(&tt);
	std::cout << "[" << ptime->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << ptime->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << ptime->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << ptime->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ptime->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ptime->tm_sec << "] ";
}

int Account::getNbAccounts(void){
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void){
	return Account::_totalAmount;
}

int Account::getNbDeposits(void){
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void){
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

// Functions
void Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits ++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits ++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal < this->_amount){
		this->_amount -= withdrawal;
		this->_nbWithdrawals ++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals ++;
		std::cout << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	} else {
		std::cout << "refused" << std::endl;
	}
	return false;
}

int Account::checkAmount(void) const {
	return this->_amount;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
