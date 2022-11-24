/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 04:11:45 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/24 04:19:43 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void) : _name("An unnamed"), _hit(10), _energy(10), _attack(0) {
	std::cout << _name << " the ClapTrap is born 👶" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "A copy of " << src._name << " ClapTrap is born 👬" << std::endl;	
	*this = src;
}

ClapTrap::~ClapTrap(void) {
		std::cout << this->_name << " the ClapTrap is gone 🪦" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hit(10), _energy(10), _attack(0) {
	std::cout << name << " the ClapTrap is born 👶" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;	
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_energy = rhs._energy;
		this->_attack = rhs._attack;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energy > 0 && this->_hit > 0)
	{
		std::cout << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attack << " points of damage !" << std::endl;
		this->_energy--;
	}
	else if (this->_hit <= 0)
		std::cout << this->_name << " is probably dead.." << std::endl;
	else
		std::cout << this->_name << " has no more energy.." << std::endl;		
}
	
void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->_name << " takes " << amount << " damage ! .. Ouille" << std::endl;
	for (unsigned int i = 0; i < amount; i++)
		this->_hit--;
	if (this->_hit <= 0)
		std::cout << this->_name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy > 0 && this->_hit > 0)
	{
		std::cout << this->_name << " is recovering of " << amount << " hit points !" << std::endl;
		for (unsigned int i = 0; i < amount; i++)
			this->_hit++;
	}
	else if (this->_hit <= 0)
		std::cout << this->_name << " is probably dead.." << std::endl;
	else
		std::cout << this->_name << " has no more energy.." << std::endl;		
}

std::string ClapTrap::getName() const {
	return (this->_name);
}

int ClapTrap::getHit() const {
	return (this->_hit);	
}

int ClapTrap::getEnergy() const {
	return (this->_energy);	
}

int ClapTrap::getAttack() const {
	return (this->_attack);	
}

void	ClapTrap::setAttack(int new_attack) {
	this->_attack = new_attack;
}
