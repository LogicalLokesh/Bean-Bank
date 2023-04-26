// Copyright (c) LogicalLokesh, All rights reserved.
//
// Description: The BankingService class.
//
// Author:      @LogicalLokesh - https://github.com/LogicalLokesh

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


/**
 * \brief BankingService class follows singleton pattern, Use GetInstance().
 */
class BankingService // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	/**
	 * \brief Create the instance, or return the reference if already instantiated.
	 * \return A reference to bank instance.
	 */
	static auto GetInstance() -> BankingService&;

private:
	BankingService() = default; // private constructor to prevent direct instantiation
	// delete copy constructor
	BankingService(const BankingService&) = delete; // NOLINT(modernize-use-equals-delete)
	// delete assignment operator
	auto operator=(const BankingService&)->BankingService & = delete; // NOLINT(modernize-use-equals-delete)
};