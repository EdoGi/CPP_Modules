/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 03:32:44 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/06 06:15:07 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <cstdlib>

template <typename T>
void print(MutantStack<T> &ref)
{
	typename MutantStack<T>::iterator it = ref.begin();
	
	std::cout << BWHT << "Print Stack :" << RESET << std::endl;
	std::cout << "| ";
	while (it != ref.end())
	{	
		std::cout << *it << BWHT << " | " << RESET;
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
void print(MutantStack<T> const &ref)
{
	typename MutantStack<T>::const_iterator it = ref.cbegin();
	
	std::cout << BWHT << "Print Stack CONST:" << RESET << std::endl;
	std::cout << "| ";
	while (it != ref.cend())
	{	
		std::cout << *it << BWHT << " | " << RESET;
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	MutantStack<int> Hello;
	
	srand(time(0));
	std::cout << BWHT<< "================= MStack Test from 1 - 10 ===============" << RESET << std::endl;
	for(int i = 1; i <= 10; ++i)
		Hello.push(rand() % 100);
	print(Hello);
	
	std::cout << BWHT<< "================= Const MStack Copy ===============" << RESET << std::endl;
	const MutantStack<int> Hello2(Hello);
	print(Hello2);
	
	std::cout << BWHT<< "================= Assign MStack ===============" << RESET << std::endl;
	MutantStack<int> copy;
	copy = Hello;
	print(copy);	
	return (0);
}