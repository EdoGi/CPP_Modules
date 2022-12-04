/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:23:39 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 03:07:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
	Data ptr = {112358, "Hello World"};
	uintptr_t raw;
	
	std::cout << "ptr has word is " << BYEL <<  ptr.word << RESET;
	std::cout << " and value : " << BYEL << ptr.value << RESET << std::endl;
	std::cout << "ptr address : " << BYEL << &ptr << RESET << std::endl;
	
	raw = serialize(&ptr);
	
	Data *ptr2 = NULL;
	
	std::cout << std::endl;
	std::cout << BCYN << "Serial is : " << raw << RESET << std::endl;
	std::cout << std::endl;

	ptr2 = deserialize(raw);
	
	std::cout << "ptr2 has word is " << BYEL <<  ptr2->word << RESET;
	std::cout << " and value : " << BYEL << ptr2->value << RESET << std::endl;
	std::cout << "ptr2 address : " << BYEL << &ptr2 << RESET << std::endl;

	return 0;
}