/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:51:54 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/12 21:31:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	PhoneBook pages_jaunes;
	
	std::string command;
	std::cout << "MAIN MENU : ADD, SEARCH or EXIT" << std::endl;
	while (std::getline(std::cin, command))
	{
		if (std::cin.eof())
			return (0);
		std::cout << "MAIN MENU : ADD, SEARCH or EXIT" << std::endl;
		if (command.compare("ADD") == 0)
			pages_jaunes.add_contact();
		if (command.compare("SEARCH") == 0)
			pages_jaunes.search();
		if (command.compare("EXIT") == 0)
			return 0;
		std::cin.clear();
	}
	return 0;
}
