/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:49:59 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 05:00:37 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nm) : _name(nm) {
	std::cout << _name << " arrives in the ring !" << std::endl;
}

HumanB::~HumanB(void){
	std::cout << _name << " is on the floor.. maybe dead?" << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
	std::cout << this->_name << " grabs " << _weapon->getType() << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}