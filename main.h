/**
 * Copyright: LogicalLokesh. All rights reserved.
 *
 * File:   main.h
 * Brief:  Welcome to the Bean Bank! A simple Banking system written in C++,
 *		   to nourish and hydrate my C++ skills.
 * Ver:    0.0.1
 * Author: LogicalLokesh (github.com/LogicalLokesh)
 * Date:   January 2023
**/

#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include "Account.h"
#include "User.h"
#include "Bank.h"

#define CONSUME_NEWLINE_CHARACTER string trash; getline(cin, trash); // consume newline character caused by previous input stream.

void setConsoleColor(uint8_t);
void showAppInfo(void);
void showMenu(void);
void createNewAccount(void);