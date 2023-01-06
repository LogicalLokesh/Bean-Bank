/**
 * Copyright: LogicalLokesh. All rights reserved.
 *
 * File:   main.cpp
 * Brief:  Welcome to the Bean Bank! A simple Banking system written in C++,
 *		   to nourish and hydrate my C++ skills.
 * Ver:    0.0.1
 * Author: LogicalLokesh (github.com/LogicalLokesh)
 * Date:   January 2023
**/

#include "main.h"

using std::cout; using std::endl;
using std::cin;
using std::string; using std::getline;


HANDLE g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		// global handle for console.


int main(void)
{
	string userChoice;
	do
	{
		showMenu(); // show main menu first every time

		getline(cin, userChoice); // wait for user's choice


		if (!userChoice.length()) // check if choice is empty, or accidentally clicked enter.
		{
			setConsoleColor(6);
			cout << "\n   Please enter a valid choice.";
			userChoice.clear();
			Sleep(2000);
			continue;
		}

		if (userChoice == "1")
		{
			userChoice.clear();
			// checkBalance();
			cout << "Check balance";
			system("pause");
			continue;
		}

		if (userChoice == "2")
		{
			userChoice.clear();
			// deposit();
			cout << "Money deposited!";
			continue;
		}

		if (userChoice == "3")
		{
			userChoice.clear();
			// Withdrawal();
			cout << "Money Withdrawal";
			continue;
		}

		if (userChoice == "4")
		{
			createNewAccount();
			userChoice.clear();
			continue;
		}

		if (userChoice == "5")
		{
			userChoice.clear();
			// closeAccount();
			cout << "account closed!";
			continue;
		}

		if (userChoice == "6")
		{
			userChoice.clear();
			// showAllAccounts();
			cout << "show all accounts";
			bank.loadUserDataFile();
			continue;
		}

		if (userChoice == "7")
			exit(0);

		// user has entered invalid choice
		setConsoleColor(6);
		cout << "   Invalid Input, please enter your choice: (1, 2, 3, 4, 5, 6, 7)";
		userChoice.clear();
		Sleep(2000);
	} while (true);
}


/**
 * \brief Changes the color of the console.
 *
 * \param colorCode (1 Blue) (2 Green) (3 Teal) (4 Red) (5 Purple) (6 Yellow) (7 White) (8 Grey)
 */
void setConsoleColor(uint8_t colorCode)
{
	SetConsoleTextAttribute(g_hConsole, colorCode);
}

/**
 * \brief Clears the console and shows application information and version info.
 *
 */
void showAppInfo(void)
{
	system("cls");
	setConsoleColor(3);
	cout << "   Bean Bank" << endl;
	setConsoleColor(2);
	cout << "   Version: 0.0.1" << endl;
	cout << "   (c) LogicalLokesh, All rights reserved." << endl;
	setConsoleColor(7);
}

/**
 * \brief Clears the console and shows the main menu.
 *
 */
void showMenu(void)
{
	SetConsoleTitleW(L"Bean Bank");
	system("cls");
	showAppInfo();
	cout << "\n   Main Menu: " << endl;
	cout << "   1. Balance Inquiry" << endl;
	cout << "   2. Deposit" << endl;
	cout << "   3. Withdrawal" << endl;
	cout << "   4. Create new Account" << endl;
	cout << "   5. Close an Account" << endl;
	cout << "   6. Show all Accounts" << endl;
	cout << "   7. Quit\n" << endl;
	cout << "   Enter your choice: ";
}

/**
 * \brief Creates a new user account.
 *
 */
void createNewAccount(void)
{
	User user;
	string firstName, lastName, address;
	int age = 0, userId = 0, userPassword = 0;
	unsigned long long phoneNumber;

	showAppInfo();
	SetConsoleTitle(L"Bean Bank | Create New Account");
	cout << "\n   - Create New Account - \n" << endl;

#pragma region Get Details

	// set first name
	while (true) {
		setConsoleColor(7);
		cout << "   First Name: ";
		getline(cin, firstName);
		if (user.setFirstName(firstName))
			break;
		setConsoleColor(4);
		cout << "   Invalid Name. It should not contain any numbers, special characters, or spaces,"
			<< "     and it should be less than 20 characters. " << endl;
		Sleep(3000);
		continue;
	}
	// set last name
	while (true) {
		setConsoleColor(7);
		cout << "   Last Name: ";
		getline(cin, lastName);
		if (user.setLastName(lastName))
			break;
		setConsoleColor(4);
		cout << "   Invalid Name. It should not contain any numbers, special characters, or spaces,"
			<< "    and it should be less than 20 characters." << endl;
		Sleep(3000);
		continue;
	}
	// set age
	while (true) {
		setConsoleColor(7);
		cout << "   Age: ";
		cin >> age;
		if (user.setAge(age))
			break;
		if (age < 18) {
			setConsoleColor(4);
			cout << "   You must be at least 18 years old to create an account." << endl;
			Sleep(3000);
			continue;
		}
		if (age > 200) {
			setConsoleColor(4);
			cout << "   Are you over 200? Check your age again." << endl;
			Sleep(3000);
			continue;
		}
	}
	// set gender
	string gender;
	while (true) {
		setConsoleColor(7);
		cout << "   1- Male, 2- Female, 3- Other\n";
		cout << "   Gender: ";
		cin >> gender;
		if (gender != "1" && gender != "2" && gender != "3") {
			setConsoleColor(4);
			cout << "   Please choose correct option." << endl;
			Sleep(3000);
			continue;
		}
		if (gender == "1")
			user.setGender(Male);
		if (gender == "2")
			user.setGender(Female);
		if (gender == "3")
			user.setGender(Other);
		break;
	}
	// set phone number
	while (true) {
		setConsoleColor(7);
		cout << "   Phone Number: ";
		cin >> phoneNumber;
		if (user.setPhoneNumber(phoneNumber))
			break;
		setConsoleColor(4);
		cout << "   Invalid phone number." << endl;
		Sleep(3000);
		continue;
	}
	// set address
	while (true) {
		setConsoleColor(7);
		cout << "   Address: ";
		CONSUME_NEWLINE_CHARACTER
			getline(cin, address);
		if (user.setAddress(address))
			break;
		setConsoleColor(4);
		cout << "   Invalid address. It must be must be greater than 2 or less than 150 characters." << endl;
		Sleep(3000);
		continue;
	}
	// set user id
	while (true) {
		setConsoleColor(7);
		cout << "   User ID: ";
		string tmp;		// temporary string for storing user id
		getline(cin, tmp);
		try
		{
			userId = std::stoi(tmp);	// try to convert string to int
		}
		catch (const std::exception)
		{
			userId = NULL;	 // set to NULL if failed
		}

		if (user.setUserId(userId))
			break;
		setConsoleColor(4);
		cout << "   Invalid User ID. It must be a number between 1 to 50,000." << endl;
		Sleep(3000);
		continue;

	}
	// set user password
	while (true) {
		setConsoleColor(7);
		cout << "   Password: ";
		string tmp;		// temporary string for storing password
		getline(cin, tmp);
		try
		{
			userPassword = std::stoi(tmp);	// try to convert string to int
		}
		catch (const std::exception)
		{
			userPassword = NULL; // set to NULL if failed
		}
		if (user.setUserPassword(userPassword))
			break;
		setConsoleColor(4);
		cout << "   Invalid password. It must be 7 digit number." << endl;
		Sleep(3000);
		continue;
	}
#pragma endregion

	// At this stage, all details are valid. Now display all user info for confirmation.
	showAppInfo();
	SetConsoleTitle(L"Bean Bank | Account Confirmation");
	cout << "\n   - Account Confirmation -\n" << endl;
	cout << "   Name: " << firstName << " " << lastName << endl;
	cout << "   Age: " << age << endl;
	cout << "   Gender: ";
	if (gender == "1")
		cout << "Male";
	if (gender == "2")
		cout << "Female";
	if (gender == "3")
		cout << "Other";
	cout << "\n   Phone Number: " << phoneNumber << endl;
	cout << "   Address: " << address << endl;
	cout << "   User ID: " << userId << endl;
	cout << "   Password: " << userPassword << endl;
	setConsoleColor(6);
	cout << "\n   Enter 1 to Create your Account. Enter 0 Otherwise." << endl;
	cout << "   CONSENT: ";
	string consent;
	getline(cin, consent);
	try
	{
		int ans = std::stoi(consent);
		if (ans != 1)
			return;
	}
	catch (const std::exception)
	{
		return;
	}

	vUsers.push_back(user);
	bank.writeUserDataFile(user);
	cout << "Account Created!";
}
