/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:55:51 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/23 09:25:16 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	_name = "An unnamed";
	_hit = 100;
	_energy = 50;
	_attack = 20;
	std::cout << _name << " the ScavTrap joined the battle ⚔️" << std::endl;	
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	std::cout << "A copy of " << src._name << " ScavTrap is HERE 👬" << std::endl;	
	*this = src;
}

ScavTrap::~ScavTrap(void) {
		std::cout << this->_name << " the ScavTrap is now in Vahalla 🏞️" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name) {
	// _name = name;
	_hit = 100;
	_energy = 50;
	_attack = 20;
	std::cout << _name << " the ScavTrap joined the battle ⚔️" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
	std::cout << "The two Scavengers are actually the same !" << std::endl;	
	if (this != &rhs)
	{
		std::cout << this->_name << " SCAV is fusioning with " << rhs._name << std::endl;	
		this->_name = rhs.getName();
		this->_hit = rhs.getHit();
		this->_energy = rhs.getEnergy();
		this->_attack = rhs.getAttack();
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energy > 0)
	{
		std::cout << "ScavTrap " << this->_name << " take his courage and charge " << target;
		std::cout << " He causes " << this->_attack << " points of damage !" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no more energy to fight.." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_energy > 0)
	{
		std::cout << "ScavTrap " << this->_name << \
			" is recovering of " << amount << " hit points !" << std::endl;
		for (unsigned int i = 0; i < amount; i++)
			this->_hit++;
	}	
}

void ScavTrap::guardGate() {
	std::cout << this->getName() << " is now in defense mode. He guard the gate !" << std::endl;
}
