/**
 * Copyright: LogicalLokesh. All rights reserved.
 *
 * File:   User.h
 * Brief:  User class for Bean Bank.
 *
 * Author: LogicalLokesh (github.com/LogicalLokesh)
 * Date:   January 2023
**/

#pragma once

#include <string>
#include "Account.h"
#include <regex>
#include <fstream>


using std::string;

typedef enum { Male = 1, Female = 2, Other = 3 } gender_t; // Gender: 1- Male, 2- Female, 3- Other.

class User : public Account
{
private:
	gender_t m_Gender;
	string m_firstName, m_lastName, m_address;
	int m_age, m_userId, m_userPassword;
	unsigned long long m_phoneNumber;

	/**
	* \brief Checks for illegal characters in name.
	*
	* \param name
	* \return true if name is valid, false otherwise.
	*/
	bool validateName(string name) {
		if (name.length() <= 2 || name.length() >= 20)
			return false;

		// check if letters are in between A to Z or a to z.
		// all other characters are not allowed including space.
		for (int i = 0; i < name.length(); i++)
		{
			if (name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122)
				continue;
			return false;
		}
		return true;	// name is valid.
	}

	/**
	* \brief Checks for the illegal characters in address.
	*
	* \param address
	* \return true if address is valid, false otherwise.
	*/
	bool validateAddress(string address) {
		// address must be greater than 2 or less than 150 characters.
		if (address.length() <= 2 || address.length() >= 150)
			return false;

		// space is not allowed in first or last position of address.
		if (address[0] == 32 || address[address.length() - 1] == 32)
			return false;

		// check if letters are in between A to Z or a to z.
		for (int i = 0; i < address.length(); i++)
		{
			if (address[i] >= 65 && address[i] <= 90 || address[i] >= 97 && address[i] <= 122)
				continue;
			if (address[i] == 32)	// space is allowed in middle of address.
				continue;
			return false;
		}
		return true;	// address is valid.
	}

	/**
	* \brief Validates the age. Age must be from 18 to 200 years.
	*
	* \param age
	* \return true if age is valid, false otherwise.
	*/
	bool validateAge(int age) { return (age >= 18 && age <= 200); }

	/**
	* \brief Validates the phone number by standard regex.
	*
	* \param number
	* \return true if phone number valid, false otherwise.
	*/
	bool validatePhoneNumber(unsigned long long number) {
		string s = std::to_string(number);		// convert number to string for regex pattern matching.

		// 1) Begins with 0 or 91
		// 2) Then contains 6,7 or 8 or 9.
		// 3) Then contains 9 digits
		const std::regex pattern("(0|91)?[6-9][0-9]{9}");

		return std::regex_match(s, pattern);
	}

	/**
	* \brief Validates userId. It must in be between 1 to 50000.
	*
	* \param userId
	* \return true if userId is valid, false otherwise.
	*/
	bool validateUserId(int userId) { return (userId > 0 && userId < 50000); }

	/**
	* \brief Validates the user password. it must be 7 digit number.
	 *
	 * \param password
	 * \return true if password is valid, false otherwise.
	 */
	bool validateUserPassword(int password) { return password >= 1000000 && password <= 9999999; }

public:
	User(string firstName = "", string lastName = "", int age = 0, unsigned long long phoneNo = 0,
		int userId = 0, int userPassword = 0, gender_t gender = Other, string address = "") {
		if (validateName(firstName))
			m_firstName = firstName;
		if (validateName(lastName))
			m_lastName = lastName;
		if (validateAge(age))
			m_age = age;
		if (validatePhoneNumber(phoneNo))
			m_phoneNumber = phoneNo;
		if (validateUserId(userId))
			m_userId = userId;
		if (validateUserPassword(userPassword))
			m_userPassword = userPassword;
		if (gender == Male || gender == Female || gender == Other)
			m_Gender = gender;
		if (validateAddress(address))
			m_address = address;
	}

	/**
	 * \brief Standard destructor.
	 */
	~User() {}

	friend std::ofstream& operator<< (std::ofstream& ofs, const User& user) {
		ofs << user.getFirstName() << '-' << user.getLastName() << '-' << user.getAge() << '-'
			<< user.getPhoneNumber() << '-' << user.getUserId() << '-' << user.getUserPassword() << '-'
			<< user.getGender() << '-' << user.getAddress() << "\n";
		return ofs;
	}

	friend  std::ifstream& operator>>(std::ifstream& ifs, const User& user) {
		std::cout << user.getFirstName() << '-' << user.getLastName() << '-' << user.getAge() << '-'
			<< user.getPhoneNumber() << '-' << user.getUserId() << '-' << user.getUserPassword() << '-'
			<< user.getGender() << '-' << user.getAddress() << "\n";
		return ifs;
	}


#pragma region Accessors and Mutators

	bool setFirstName(string name) {
		if (!validateName(name))
			return false;
		m_firstName = name;
		return true;
	}

	string getFirstName(void) const { return m_firstName; }

	bool setLastName(string name) {
		if (!validateName(name))
			return false;
		m_lastName = name;
		return true;
	}

	string getLastName(void) const { return m_lastName; }

	bool setAddress(string address) {
		if (!validateAddress(address))
			return false;
		m_address = address;
		return true;
	}

	string getAddress(void) const { return m_address; }

	bool setGender(gender_t gender) {
		if (gender == Male || gender == Female || gender == Other)
		{
			m_Gender = gender;
			return true;
		}
		return false;
	}

	gender_t getGender(void) const { return m_Gender; }

	bool setAge(int age) {
		if (!validateAge(age))
			return false;
		m_age = age;
		return true;
	}

	int getAge(void) const { return m_age; }

	bool setPhoneNumber(unsigned long long number) {
		if (!validatePhoneNumber(number))
			return false;
		m_phoneNumber = number;
		return true;
	}

	unsigned long long getPhoneNumber(void) const { return m_phoneNumber; }

	bool setUserId(int userId) {
		if (!validateUserId(userId))
			return false;
		m_userId = userId;
		return true;
	}

	int getUserId(void) const { return m_userId; }

	bool setUserPassword(int password) {
		if (!validateUserPassword(password))
			return false;
		m_userPassword = password;
		return true;
	}

	int getUserPassword(void) const { return m_userPassword; }

#pragma endregion


};