/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:50:07 by giaco             #+#    #+#             */
/*   Updated: 2022/11/28 01:34:01 by giaco            ###   ########.fr       */
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
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
/* 	std::cout << std::endl;
	std::cout << "Test compare to abstract" << std::endl;
	Animal Test_pour_après;
	std::cout << std::endl; */

	delete j; //should not create a leak
	delete i;

	std::cout << std::endl;
	std::cout << "### MY MAIN (Mandatory) ###" << std::endl;
	std::cout << std::endl;
	
	std::cout << "-> Instantiation <-" << std::endl;
	std::cout << std::endl;	
	const Animal *AniGroup[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			AniGroup[i] = new Dog();
		else
			AniGroup[i] = new Cat();
		std::cout << std::endl << "We have create " << i + 1 << " animals" << std::endl << std::endl;
	}

	std::cout << std::endl;		
	std::cout << "-> Make Sounds ! <-" << std::endl;
	std::cout << std::endl;
		
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << " : " << AniGroup[i]->getType() << " Says : " << std::endl;
		AniGroup[i]->makeSound();
	}		
	
	std::cout << std::endl;		
	std::cout << "-> Destruction ! <-" << std::endl;
	std::cout << std::endl;
	
	for (int i = 0; i < 10; i++)
	{
		delete AniGroup[i];
	}
	
	std::cout << std::endl;	
	std::cout << "-> Check Deep Copy ! <-" << std::endl;
	std::cout << std::endl;	
	
	const Cat *FirstCat = new Cat();
	const Cat *SecondCat = new Cat(*FirstCat);

	delete FirstCat;
	delete SecondCat;
	
	std::cout << std::endl;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # : Constructor" << std::endl;
	Cat origin;
	std::cout << std::endl << " # ~~~~~~~~~~~~~~~~~~~~~~ # : Copy Constructor" << std::endl;
	Cat copy(origin);
	std::cout << std::endl << " # ~~~~~~~~~~~~~~~~~~~~~~ # : Assign Operator to Tmp" << std::endl;
	Brain *braintest;
	Cat assign;
	braintest = assign.getBrain();
	braintest->setIdea(0, "Je n'aime pas les humains ! rrrrrrr");
	{
		std::cout << "Idée 0 Cat Brain Test : " << assign.getBrain()->_ideas[0] << std::endl;	
		Cat tmp = assign;
	}
	std::cout << "Idée 0 Cat Brain Test : " << assign.getBrain()->_ideas[0] << std::endl;	
	std::cout << std::endl << " # ~~~~~~~~~~~~~~~~~~~~~~ # : Assign Operator check values" << std::endl;
	assign = origin;
	std::cout << std::endl << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	
	return 0;
}
