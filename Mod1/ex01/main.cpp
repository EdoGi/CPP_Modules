/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:06:09 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 03:31:26 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

int main(int ac, char **av)
{
	if(ac == 3)
	{
		std::stringstream	conv;
		int					n;
		
		(void)ac;
		conv << av[1];
		conv >> n;
		Zombie* The_Horde = zombieHorde(n, av[2]);
		for (int i = 0; i < n; i++)
			The_Horde->announce();
		delete [] The_Horde;
	}
	return 0;
}
