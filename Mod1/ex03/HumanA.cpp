/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:49:43 by egiacomi          #+#    #+#             */
/*   Updated: 2023/04/05 01:11:37 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon& wp) : _name(nm), _weapon(wp){
	std::cout << _name << " arrives in the ring and grab a " << _weapon.getType() << " !" << std::endl;
}

HumanA::~HumanA(void){
	std::cout << _name << " is on the floor.. maybe dead?" << std::endl;
}

void	HumanA::setWeapon(Weapon new_weapon)
{
	this->_weapon.setType(new_weapon.getType());
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
