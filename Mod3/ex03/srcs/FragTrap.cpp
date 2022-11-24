/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:57:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/24 04:21:17 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Anonymous") {
	_hit = 100;
	_energy = 50;
	_attack = 20;
	std::cout << _name << " FragTrap is just here to have fun 🙋🏻" << std::endl;	
}

FragTrap::FragTrap(FragTrap const & src) {
	std::cout << "The " << src._name << " FragTrap didn't came alone" << std::endl;	
	*this = src;
}

FragTrap::~FragTrap(void) {
		std::cout << this->_name << " the FragTrap is bored.. so just left 🥱" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	// _name = name;
	_hit = 100;
	_energy = 100;
	_attack = 30;
	std::cout << _name << " FragTrap is just here to have fun 🙋🏻" << std::endl;	
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
	std::cout << rhs._name << " FragTrap has a gemini ♊" << std::endl;	
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit = rhs.getHit();
		this->_energy = rhs.getEnergy();
		this->_attack = rhs.getAttack();
	}
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (this->_energy > 0)
	{
		std::cout << "FragTrap " << this->_name << " throw some popcorns 🍿" << target;
		std::cout << " He causes " << this->_attack << " points of damage !" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "FragTrap " << this->_name << " is falling asleep.." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::string input;
	
	std::cout << this->getName() << " is happy, it comes to you and say HighFive bro!" << std::endl;
	std::cout << "What do you say ?" << std::endl;
	getline(std::cin, input);
	if (input == "HighFive" || input == "highfive" || input == "Highfive" || input == "HIGHFIVE")
		std::cout << "You made a new friend" << std::endl;
	else
		std::cout << this->_name << " looks at you like.. 'Whoat ?' and moves." << std::endl;	
}
