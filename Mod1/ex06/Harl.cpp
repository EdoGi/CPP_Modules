/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:11:59 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/17 02:59:58 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl woke up du pied gauche.." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl go to bed with a sentiment de satisfaction." << std::endl;
}

void	Harl::complain(std::string level)
{
	int i;
	
	std::string	match[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i <= 4; i++)
	{
		if (level == match[i])
			break;
	}
	switch (i) {
		case 0:
			_debug();
			/* fall through */
		case 1:
			_info();
			/* fall through */
		case 2:
			_warning();
			/* fall through */
		case 3:
			_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void	Harl::_debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
}