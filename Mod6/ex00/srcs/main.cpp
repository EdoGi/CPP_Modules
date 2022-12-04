/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:23:39 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 01:11:58 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Caster.hpp"

int main (int ac, char **av)
{
	if (ac == 2)
	{
		Caster Convert(av[1]);
		Convert.displayer(Convert);
	}
	else
	{	
		std::cout << "Please enter ONE argument. Can be :" << std::endl;
		std::cout << " - a CHAR ('a', 'b', 'r', ...)" << std::endl;
		std::cout << " - an INT (0, 1, 15, -15, ...)" << std::endl;
		std::cout << " - a FLOAT (0.0f, -4.2f, 4.2f, ...)" << std::endl;
		std::cout << " - a DOUBLE (0.0, -4.2, 4.2, ...)" << std::endl;
	}
	return 0;
}