/**
 * Copyright: LogicalLokesh. All rights reserved.
 *
 * File:   Account.h
 * Brief:  Account class for Bean Bank.
 *
 * Author: LogicalLokesh (github.com/LogicalLokesh)
 * Date:   January 2023
**/

#pragma once

#include <random>
#include <set> 


class Account
{
private:
	unsigned long long m_accountNumber = 0;
	int m_balance = 0;

	/**
	 * \brief Validates the account number. It must be 10 digit number.
	 *
	 * \param accountNumber
	 * \return true if valid, false otherwise.
	 */
	bool validateAccountNumber(unsigned long long accountNumber)
	{
		return accountNumber >= 999999999 && accountNumber <= 9999999999;
	}

public:
	/**
	 * \brief Generate a truly random Account number.
	 *
	 * \return 10 digit random number.
	 */
	unsigned long long generateAccountNumber(void) {

		std::set<unsigned long long> uniqueNums;	// Set to store unique numbers
		std::mt19937 rng(std::random_device{}());	// Use a random number generator
		std::uniform_int_distribution<unsigned long long> dist(1000000000, 9999999999);

		// Generate 10-digit numbers until we have a unique one
		while (uniqueNums.size() < 10)
			uniqueNums.insert(dist(rng)); // insert a random 10-digit number

		return *uniqueNums.begin();	// Return the first unique number
	}

	bool setBalance(int money) {
		m_balance += money;
		return true;
	}

	int getBalance(void) const { return m_balance; }

	bool setAccountNumber(unsigned long long accountNumber) {
		if (!validateAccountNumber(accountNumber))
			return false;
		m_accountNumber = accountNumber;
		return true;
	}

	unsigned long long getAccountNumber(void) const { return m_accountNumber; }
};

