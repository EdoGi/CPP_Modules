/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:22:47 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/12 23:24:38 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";created";
	std::cout << std::endl;
	_totalAmount += this->_amount;
	_nbAccounts++;
	return;
}

Account::~Account(void)
{

}