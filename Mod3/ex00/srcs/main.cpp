/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 04:02:52 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/23 09:17:49 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	
/* ######################## */
/* Instantiation de classes */
/* ######################## */
	std::cout << std::endl << "##### Instantiation #####" << std::endl << std::endl;

	ClapTrap Bob("Bob");
	ClapTrap Stef;
	ClapTrap Jim("Jim");

	std::cout << Bob.getName() << " has " << Bob.getHit() << " life and " << Bob.getEnergy() << " energy points." << std::endl;
	std::cout << Stef.getName() << " has " << Stef.getHit() << " life and " << Stef.getEnergy() << " energy points." << std::endl;
	std::cout << Jim.getName() << " has " << Jim.getHit() << " life and " << Jim.getEnergy() << " energy points." << std::endl;

	Stef = Bob;
	std::cout << Stef.getName() << " has " << Stef.getHit() << " life and " << Stef.getEnergy() << " energy points." << std::endl;
	
/* ######################## */
/* 			Actions		    */
/* ######################## */
	std::cout << std::endl << "##### Actions #####" << std::endl << std::endl;
	int i;

	std::cout << std::endl << "----- Set Attack -----" << std::endl << std::endl;

	std::cout << Bob.getName() << " is " << Bob.getAttack() << " strong." << std::endl;
	Bob.setAttack(1);
	std::cout << Bob.getName() << " is " << Bob.getAttack() << " strong." << std::endl;

	std::cout << std::endl << "----- Attack -----" << std::endl << std::endl;
	for (i = 0; i < 5; i++)
		Bob.attack(Jim.getName());
	Jim.takeDamage(i);
	
	std::cout << std::endl << "----- Check life -----" << std::endl << std::endl;

	std::cout << Jim.getName() << " has " << Jim.getHit() << " life points now" << std::endl;
	Jim.beRepaired(3);
	std::cout << Jim.getName() << " has " << Jim.getHit() << " life points now" << std::endl;

	std::cout << std::endl << "##### Finish #####" << std::endl << std::endl;

	return 0;
}
