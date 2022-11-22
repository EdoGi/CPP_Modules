/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 04:11:45 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/22 04:23:35 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void) {
	std::cout << "A ClapTrap is born" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "A copy of " << src.getName() << " ClapTrap is born" << std::endl;	
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;	
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit = rhs.getHit();
		this->_energy = rhs.getEnergy();
		this->_attack = rhs.getAttack();
	}
	return (*this);
}

ClapTrad & 

		ClapTrap & operator=(ClapTrap const & rhs);
		~ClapTrap(void);

		void		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName();
		int			getHit();
		int			getEnergy();
		int			getAttack();	