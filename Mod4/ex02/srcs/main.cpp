/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:50:07 by giaco             #+#    #+#             */
/*   Updated: 2022/11/28 01:37:34 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "~~~~.~~~~ MAIN TEST ~~~~.~~~~" << std::endl;
	
/* 	std::cout << std::endl;
	std::cout << "Test compare to abstract" << std::endl;
	AAnimal Test_pour_maintenanr;
	std::cout << std::endl; */
		
	AAnimal *AAniArray[4];
	
	for (int i = 0; i < 4; i++)
	{
		if (i % 2) // index 1 & 3
			AAniArray[i] = new Cat();
		else
			AAniArray[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << "Should sound like a cat : ";
	AAniArray[1]->makeSound();
	std::cout << "Should sound like a dog : ";
	AAniArray[0]->makeSound();
	std::cout << std::endl << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete AAniArray[i];
			
	return 0;
}
