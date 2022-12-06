/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:44:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/06 06:13:13 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

template<typename T>
void print(T & ref)
{
	typename T::iterator it = ref.begin();
	
	std::cout << "| ";
	while (it != ref.end())
	{	std::cout << *it << " | "; ++it;}
	std::cout << std::endl;
}

int main()
{
	srand(time(0));
	std::cout << BWHT<< "\n\n================= Int List ===============" << RESET << std::endl;
	std::list<int> listInt;
	std::cout << "\n*~~~~~~~~~~~~~~ 5 Random Numbers ~~~~~~~~~~~~~~*" << std::endl;
	int value;
	for(int i = 0; i < 30; ++i)
	{
		value = rand() % 100;
		listInt.push_front(value);
	}
	print(listInt);
	std::cout << "\n*~~~~~~~~~~~~~~ Try with 100 Random Numbers ~~~~~~~~~~~~~~*" << std::endl;
	for(int i = 0; i <= 5; ++i)
	{
		value = rand() % 100;
		if (easyfind(listInt, value))
			std::cout << "I found value " << BGRN << value << RESET << " in listInt !!" << std::endl;
		else
			std::cout << BRED << value << RESET  " Not found !" << std::endl;	
	}
	listInt.push_back(101);
	std::cout << "\n*~~~~~~~~~~~~~~ With Occurence ~~~~~~~~~~~~~~*" << std::endl;
	if (easyfind(listInt, 101))
			std::cout << "I found value " << BGRN << 101 << RESET << " in listInt !!" << std::endl;
	std::cout << "\n*~~~~~~~~~~~~~~ No Occurence ~~~~~~~~~~~~~~*" << std::endl;
	if (easyfind(listInt, 102))
			std::cout << "I found value " << BGRN << 102 << RESET << " in listInt !!" << std::endl;
	else
			std::cout << BRED << 102 << RESET  " Not found !" << std::endl;

	std::cout << BWHT<< "================= Int Vector ===============" << RESET << std::endl;
	std::vector<char> vecChar;

	vecChar.push_back(5);
	vecChar.push_back(6);
	vecChar.push_back(7);
	vecChar.push_back(8);

	std::cout << "\n*~~~~~~~~~~~~~~ No Occurence ~~~~~~~~~~~~~~*" << std::endl;
	if (easyfind(vecChar, 87))
			std::cout << "I found " << BGRN << 87 << RESET << " in vecChar !!" << std::endl;
	else
			std::cout << BRED << 87 << RESET  " Not found !" << std::endl;
	std::cout << "\n*~~~~~~~~~~~~~~ With Occurence ~~~~~~~~~~~~~~*" << std::endl;
	if (easyfind(vecChar, 7))
			std::cout << "I found " << BGRN << 7 << RESET << " in vecChar !!" << std::endl;
	else
			std::cout << BRED << 7 << RESET  " Not found !" << std::endl;
	return(0);
}
