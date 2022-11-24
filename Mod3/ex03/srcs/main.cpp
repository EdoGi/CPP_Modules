/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 04:02:52 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/24 04:56:45 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
	
/* ######################## */
/* Instantiation de classes */
/* ######################## */
	std::cout << std::endl << "##### Instantiation #####" << std::endl << std::endl;

	ClapTrap Bob("Bob");
	ScavTrap Jim("Jim");
	DiamondTrap Problems("Bitch");

	std::cout << std::endl;

	std::cout << Bob.getName() << " has " << Bob.getHit() << " life and " << Bob.getEnergy() << " energy points." << std::endl;
	std::cout << Jim.getName() << " has " << Jim.getHit() << " life and " << Jim.getEnergy() << " energy points." << std::endl;
	std::cout << Problems.getName() << " has " << Problems.getHit() << " life and " << Problems.getEnergy() << " energy points." << std::endl;

	std::cout << std::endl;

	Problems.whoAmI();
	
	std::cout << std::endl;
	
	DiamondTrap Check;

	std::cout << std::endl;

	Check.whoAmI();
	
	std::cout << std::endl;
	
	Check = Problems;
	
	std::cout << std::endl;
	
	DiamondTrap Copy(Check);
	
/* ######################## */
/* 			Actions		    */
/* ######################## */
	std::cout << std::endl << "##### Actions #####" << std::endl << std::endl;
	int i;

	std::cout << std::endl << "----- Set Attack -----" << std::endl << std::endl;

	std::cout << Copy.getName() << " is " << Copy.getAttack() << " strong." << std::endl;
	Copy.setAttack(1);
	std::cout << Copy.getName() << " is " << Copy.getAttack() << " strong." << std::endl;

	std::cout << std::endl << "----- Attack -----" << std::endl << std::endl;
	for (i = 0; i < 5; i++)
		Copy.attack(Problems.getName());
	Problems.takeDamage(i);
		
	std::cout << std::endl << "----- CHILL -----" << std::endl << std::endl;

	Problems.highFivesGuys();

	std::cout << std::endl << "----- Check life -----" << std::endl << std::endl;

	std::cout << Problems.getName() << " has " << Problems.getHit() << " life points now" << std::endl;
	Problems.beRepaired(3);
	std::cout << Problems.getName() << " has " << Problems.getHit() << " life points now" << std::endl;
	
	std::cout << std::endl << "----- Defense -----" << std::endl << std::endl;

	Problems.guardGate();
	
	std::cout << std::endl << "##### Finish #####" << std::endl << std::endl;

	return 0;
}
