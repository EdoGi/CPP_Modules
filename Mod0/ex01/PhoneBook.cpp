/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:08:30 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/12 21:25:57 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook (void)
{
	this->nb = 0;
	
	std::cout << "Motorola PhoneBook : Welcome !" << std::endl;
	return;
}

PhoneBook::~PhoneBook (void)
{
	std::cout << "Motorola PhoneBook : GoodBye !" << std::endl;
	return;
}

void	PhoneBook::add_contact(void)
{
	int		index;
	int		cnum(this->nb);

	std::cout << std::endl;
	index = cnum % 8;
	if (cnum > 7)
		contact[index].clear_contact();
	contact[index].fill_infos(index);	
	this->nb++;
	std::cout << "New Contact " << contact[index].get_First() << " has been created" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "MAIN MENU : ADD, SEARCH or EXIT" << std::endl;
}

void	PhoneBook::search(void)
{
	int	choice;

	if (this->nb == 0)
	{
		std::cout << std::endl << "Empty Pages Jaunes at the moment" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "MAIN MENU : ADD, SEARCH or EXIT" << std::endl;
	}
	else
	{
		display();
		std::cout << "What contact would you like to check ?" << std::endl;
		std::cout << "Type Contact Index or 0 to go back to the Menu" << std::endl;
		while ( !(std::cin >> choice) || (choice < 0 || choice > this->nb || choice > 8 ))
		{
			std::cin.clear();
  			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "That is not a valid index. Please retry." << std::endl;
		}
		if (choice == 0)
		{
			std::cout << "-------------------------------------------" << std::endl;
		}
		else
			this->contact[choice - 1].display_detail();
	}
}

void	PhoneBook::display(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; (i < this->nb) && (i < 8); i++)
		this->contact[i].display_contact();
	std::cout << "|-------------------------------------------|" << std::endl;
}