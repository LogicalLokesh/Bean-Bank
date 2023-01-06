/**
 * Copyright: LogicalLokesh. All rights reserved.
 *
 * File:   Bank.h
 * Brief:  Bank class for Bean Bank.
 *
 * Author: LogicalLokesh (github.com/LogicalLokesh)
 * Date:   January 2023
**/

#pragma once

#include"User.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using std::string, std::getline;
using std::vector;
using std::ifstream, std::ofstream;

vector<User> vUsers;	// vector for storing users

class Bank
{
private:
	unsigned int m_usersCount = 0, m_balance = 0;

public:
	/**
	 * \brief Loads the user_data file into vUsers.
	 *
	 * \return
	 */
	bool loadUserDataFile(void) {
		ifstream in("user_data.txt");
		if (!in.is_open())
			return false;
		string line;
		while (getline(in, line))
		{
			// Iterate over every line and load it into a string.
			// then convert the string into corresponding types.
			std::stringstream ss(line);
			string firstName, lastName, address, age_str, userId_str,
				userPassword_str, phoneNumber_str, gender_str;
			getline(ss, firstName, '-');
			getline(ss, lastName, '-');
			getline(ss, age_str, '-');
			getline(ss, phoneNumber_str, '-');
			getline(ss, userId_str, '-');
			getline(ss, userPassword_str, '-');
			getline(ss, gender_str, '-');
			getline(ss, address, '-');

			gender_t Gender = Other;
			int age = 0, userId = 0, userPassword = 0, gender = 0;
			unsigned long long phoneNumber = 0;
			// try conversion. if anything fails, catch and return false;
			try
			{
				age = std::stoi(age_str);
				phoneNumber = std::stoull(phoneNumber_str);
				userId = std::stoi(userId_str);
				userPassword = std::stoi(userPassword_str);
				gender = std::stoi(gender_str);
			}
			catch (const std::exception&)
			{
				return false;
			}

			if (gender == 1)
				Gender = Male;
			if (gender == 2)
				Gender = Female;
			// all required data is valid. now create user and load it into vUsers.
			User user(firstName, lastName, age, phoneNumber, userId, userPassword, Gender, address);
			vUsers.push_back(user);
		}
		in.close();
		return true;
	}

	/**
	 * \brief Write vUsers into user_data file.
	 *
	 * \return
	 */
	bool writeUserDataFile(void) {
		ofstream out("user_data.txt", std::ios::trunc);
		if (!out.is_open())
			return false;
		for (User& user : vUsers)
			out << user;
		out.close();
		return true;
	}

	/**
	 * \brief Write user to user_data file.
	 *
	 * \param user
	 * \return
	 */
	bool writeUserDataFile(const User& user) {
		ofstream out("user_data.txt", std::ios::app);
		if (!out.is_open())
			return false;
		out << user;
		out.close();
		return true;
	}

	/**
	 * \brief Add balance to the bank.
	 *
	 * \param val
	 * \return true on success.
	 */
	bool addBalance(int val) {
		m_balance += val;
		return true;
	}

#pragma region Accessors and Mutators

	unsigned int getTotalUserCount(void) const { return m_usersCount; }

	bool setTotalUserCount(unsigned int count) {
		m_usersCount = count;
		return true;
	}

	unsigned int getBalance(void) const { return m_balance; }

	bool setBalance(unsigned int balance) {
		m_balance = balance;
		return true;
	}

#pragma endregion

};

Bank bank;