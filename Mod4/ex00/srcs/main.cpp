/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:50:07 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 04:15:39 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "### SUBJECT MAIN ###" << std::endl;
	std::cout << std::endl;
	
	std::cout << "-> Instantiation <-" << std::endl;
	std::cout << std::endl;	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;		
	std::cout << "-> Get Types ! <-" << std::endl;
	std::cout << std::endl;
		
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;		
	std::cout << "-> Make Sounds ! <-" << std::endl;
	std::cout << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;		
	std::cout << "-> Destructors ! <-" << std::endl;
	std::cout << std::endl;
	
	delete i;
	delete j;
	delete meta;

	std::cout << "### MY MAIN (with WrongAnimal) ###" << std::endl;
	std::cout << std::endl;
	
	std::cout << "-> Instantiation <-" << std::endl;
	std::cout << std::endl;	
	const WrongAnimal* WA = new WrongAnimal();
	const WrongAnimal* WC = new WrongCat();

	std::cout << std::endl;		
	std::cout << "-> Get Types ! <-" << std::endl;
	std::cout << std::endl;
		
	std::cout << WA->getType() << " " << std::endl;
	std::cout << WC->getType() << " " << std::endl;

	std::cout << std::endl;		
	std::cout << "-> Make Sounds ! <-" << std::endl;
	std::cout << std::endl;
	
	WA->makeSound();
	WC->makeSound(); // Should output WrongAnimal sound
	
	std::cout << std::endl;		
	std::cout << "-> Destructors ! <-" << std::endl;
	std::cout << std::endl;
	
	delete WC;
	delete WA;
		
	return 0;
}
