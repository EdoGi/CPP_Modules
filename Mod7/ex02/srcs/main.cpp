/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:04 by giaco             #+#    #+#             */
/*   Updated: 2023/04/14 11:15:04 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define SIZE 3

int	main(void)
{
	std::cout << BWHT<< "================= Int Array ===============" << RESET << std::endl;
	
	Array<int>	intArray(SIZE);

	std::cout << "Array size : " << intArray.size() << std::endl;
	
	srand(time(NULL));
	for (unsigned int i = 0; i < intArray.size(); i++)
	{
		int	value = (std::rand() % 100) + 1;	// Range 1 to 100
		std::cout << "random value : " << value << std::endl;
		intArray[i] = value;
	}
	
	std::cout << std::endl << UCYN << "Int Array infos:" << RESET << std::endl;
	std::cout << intArray << std::endl;
	std::cout << "Value at a valid index: [0] = " << intArray[0] << std::endl;
	std::cout << "Value at a unvalid index: [5] = ";
	try 
	{
		std::cout << intArray[5] << std::endl;
	}
	catch(const std::exception &e)
    {
        std::cerr << BRED << e.what() << RESET << std::endl;
    }

	std::cout << "\n*~~~~~~~~~~~~~~ With Copy ~~~~~~~~~~~~~~*" << RESET << std::endl;
	Array<int>	intCopy(intArray);
	std::cout << std::endl << UCYN << "Int Copy infos:" << RESET << std::endl;
	std::cout << intCopy;
	std::cout << "Value at a valid index: [1] = " << intCopy[1] << std::endl;
	std::cout << "Value at a unvalid index: [5] = ";
	try 
	{
		std::cout << intCopy[5] << std::endl;
	}
	catch(const std::exception &e)
    {
        std::cerr << BRED << e.what() << RESET << std::endl;
    }

	std::cout << UWHT << "\nCheck Deep Copy:" << RESET << std::endl;
	std::cout << "Change intCopy[0] = 42;" << std::endl;
	intCopy[0] = 42;
	std::cout << "intArray: [0] = " << intArray[0] << std::endl;
	std::cout << "intCopy Array: [0] = " << intCopy[0] << std::endl;



	std::cout << BWHT<< "\n\n================= String Array ===============" << RESET << std::endl;

	Array<std::string>	strArray(SIZE);

	std::cout << "Array size : " << intArray.size() << std::endl;

	strArray[0] = "Salut";
	strArray[1] = "les";
	strArray[2] = "nazes";

	std::cout << std::endl << UCYN << "Str Array infos:" << RESET << std::endl;
	std::cout << strArray << std::endl;
	std::cout << "Value at a valid index: [0] = " << strArray[0] << std::endl;
	std::cout << "Value at a unvalid index: [5] = ";
	try 
	{
		std::cout << strArray[5] << std::endl;
	}
	catch(const std::exception &e)
    {
        std::cerr << BRED << e.what() << RESET << std::endl;
    }

	std::cout << "\n*~~~~~~~~~~~~~~ With Copy ~~~~~~~~~~~~~~*" << RESET << std::endl;
	Array<std::string>	strCopy(strArray);
	std::cout << std::endl << UCYN << "Str Copy infos:" << RESET << std::endl;
	std::cout << strCopy;
	std::cout << "Value at a valid index: [2] = " << strCopy[2] << std::endl;
	std::cout << "Value at a unvalid index: [5] = ";
	try 
	{
		std::cout << strCopy[5] << std::endl;
	}
	catch(const std::exception &e)
    {
        std::cerr << BRED << e.what() << RESET << std::endl;
    }

	std::cout << UWHT << "\nCheck Deep Copy:" << RESET << std::endl;
	std::cout << "Change strCopy[2] = boloss <3;" << std::endl;
	strCopy[2] = "boloss <3";
	std::cout << UCYN << "Str Array infos:" << RESET << std::endl;
	std::cout << strArray;
	std::cout << UCYN << "Str Copy infos:" << RESET << std::endl;
	std::cout << strCopy << std::endl;

	std::cout << UWHT << "Check by Assignation:" << RESET << std::endl;
	Array<std::string>	strtmp;
	strtmp = strCopy;
	std::cout << UCYN << "strtmp infos:" << RESET << std::endl;
	std::cout << strtmp << std::endl;

	return (0);
}