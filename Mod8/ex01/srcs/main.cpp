/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:43:43 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/06 08:10:05 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define SIZE 100

int main()
{	
	std::cout << BWHT<< "================= Subject Test ===============" << RESET << std::endl;
	
	Span	sp = Span(5);
	
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	
	sp.print_table();

	std::cout << BWHT<< "\n================= Exceptions Test ===============" << RESET << std::endl;

	srand(time(0));
	Span sp2 = Span(20);
	
	sp2.print_table();
	
	std::cout << BWHT<< "\n================= Add Plage Number ===============" << RESET << std::endl;
	sp2.addPlageNumber(10);

	sp2.print_table();

	
	std::cout << BWHT<< "\n================= Add with Range Iterator ===============" << RESET << std::endl;
	std::vector<int> tmp;

	for(int i = 0; i < 8; i++)
		tmp.push_back(rand() % 100 + 100);

	try
	{
		sp2.addRange(tmp.begin(), tmp.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	sp2.print_table();

	try
	{
		sp2.addRange(tmp.begin(), tmp.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return (0);
}