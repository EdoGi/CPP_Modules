/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:41:38 by egiacomi          #+#    #+#             */
/*   Updated: 2023/05/15 14:40:36 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error : correct usage ./RPN <inverted Polish mathematical expression>" << std::endl;
		return FAILURE;
	}
	
	try
	{
		RPN myPolish(av[1]);
		std::cout << myPolish << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return  FAILURE;
	}
	
	return SUCCESS;
}