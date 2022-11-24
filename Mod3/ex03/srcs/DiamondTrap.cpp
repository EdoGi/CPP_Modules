/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:44:09 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/24 04:55:32 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Unnamed Clap Diamond"), FragTrap("hmm"), ScavTrap("hey"), _name("Unnamed Diamond") {
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_attack = FragTrap::_attack;
	std::cout << _name << " DiamondTrap a strange apparition 💎" << std::endl;	
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name) {
	std::cout << "The " << src._name << " DiamondTrap is made for two 💍" << std::endl;	
	*this = src;
}

DiamondTrap::~DiamondTrap(void) {
		std::cout << this->_name << " the DiamondTrap never break but leave.." << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_Diamond"), FragTrap(""), ScavTrap(""), _name(name) {
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_attack = FragTrap::_attack;
	std::cout << _name << " DiamondTrap a strange apparition 💎" << std::endl;	
}
	
DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs) {
	std::cout << rhs._name << " DiamondTrap is multiplying 💠" << std::endl;	
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_energy = rhs._energy;
		this->_attack = rhs._attack;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "This Diamond name is : " << _name;
	std::cout << " But he is also known as : " << ClapTrap::_name << std::endl;
}
