/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:13:30 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 00:14:16 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

Contact::Contact (void)
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_num = "";
	this->_secret = "";

	// std::cout << "Contact created" << std::endl;
	return;
}

Contact::~Contact (void)
{
	// std::cout << "Contact deleted" << std::endl;
	return;
}

void	Contact::clear_contact(void)
{
    _first_name.clear();
    _last_name.clear();
    _nickname.clear();
    _phone_num.clear();
    _secret.clear();
}

void	Contact::display_contact(void)
{	
	std::cout << "|";
	std::cout << std::setw(10) << this->_index + 1;
	std::cout << "|";
	if (this->_first_name.length() > 9)
		std::cout << std::setw(9) << this->_first_name.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->_first_name;
	std::cout << "|";
	if (this->_last_name.length() > 9)
		std::cout << std::setw(9) << this->_last_name.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->_last_name;
	std::cout << "|";
	if (this->_nickname.length() > 9)
		std::cout << std::setw(9) << this->_nickname.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->_nickname;
	std::cout << "|" << std::endl;
}

void	Contact::display_detail(void)
{
	std::cout << std::endl << "Contact " << this->_index + 1 << " Informations :" << std::endl;
	std::cout << "First Name    : " << this->_first_name << std::endl;
	std::cout << "Last Name     : " << this->_last_name << std::endl;
	std::cout << "Nickname      : " << this->_nickname << std::endl;
	std::cout << "Phone         : " << this->_phone_num << std::endl;
	std::cout << this->_first_name << "'s Darkest Secret : " << this->_secret << std::endl;
	std::cout << std::endl;
}

void	Contact::fill_infos(int index)
{
	std::string	input;
	
	this->_index = index;
	std::cout << "Create new contact" << std::endl;
	while (_first_name.empty())
	{
		std::cout << "> First name : ";
		getline(std::cin, input);
		set_First(input);
		if (std::cin.eof())
			return;
		std::cin.clear();
		if (_first_name.empty())
			std::cout << "Blank field. Please type something." << std::endl;
	}
	while (_last_name.empty())
	{
		std::cout << "> Last name : ";
		getline(std::cin, input);
		set_Last(input);
		if (std::cin.eof())
			return;
		std::cin.clear();
		if (_last_name.empty())
			std::cout << "Blank field. Please type somthing." << std::endl;
	}
	while (_nickname.empty())
	{
		std::cout << "> Nickname : ";
		getline(std::cin, input);
		set_Nick(input);
		if (std::cin.eof())
			return;
		std::cin.clear();
		if (_nickname.empty())
			std::cout << "Blank field. Please type somthing." << std::endl;
	}
	while (_phone_num.empty())
	{
		std::cout << "> Phone number : ";
		getline(std::cin, input);
		set_Phone(input);
		if (std::cin.eof())
			return;
		std::cin.clear();
		if (_phone_num.empty())
			std::cout << "Blank field. Please type somthing." << std::endl;
	}
	while (_secret.empty())
	{
		std::cout << "> Darkest Secret : ";
		getline(std::cin, input);
		set_Secret(input);
		if (std::cin.eof())
			return;
		std::cin.clear();
		if (_secret.empty())
			std::cout << "Blank field. Please type somthing." << std::endl;
	}
}

void	Contact::set_First (std::string str)
{
	this->_first_name = str;
	return;
}

std::string	Contact::get_First (void) const
{
	return this->_first_name;
}

void	Contact::set_Last (std::string str)
{
	this->_last_name = str;
	return;
}

std::string	Contact::get_Last (void) const
{
	return this->_last_name;
}

void	Contact::set_Nick (std::string str)
{
	this->_nickname = str;
	return;
}

std::string	Contact::get_Nick (void) const
{
	return this->_nickname;
}

void	Contact::set_Phone (std::string str)
{
	this->_phone_num = str;
	return;
}

std::string	Contact::get_Phone (void) const
{
	return this->_phone_num;
}

void	Contact::set_Secret (std::string str)
{
	this->_secret = str;
	return;
}

std::string	Contact::get_Secret (void) const
{
	return this->_secret;
}
