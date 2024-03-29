/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:49:38 by egiacomi          #+#    #+#             */
/*   Updated: 2023/04/05 01:11:48 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string nm) : _type(nm){
	std::cout << "God creates " << _type << " !" << std::endl;
}

Weapon::~Weapon(void){
	std::cout << "Suddenly, " << _type << " vanish !" << std::endl;
}

void	Weapon::setType(std::string god_craft)
{
	this->_type = god_craft;
	std::cout << "Omagad ! God changes the weapon to " << god_craft << " !!" << std::endl;
}

std::string const &	Weapon::getType(void)
{
	std::string	&action = this->_type;
	return action;
}
