/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:31:32 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/14 02:46:05 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl 		this_harl;
	std::string	level;
	std::cout << UYEL << "Please enter a level of complaint:" << RESET <<std::endl;
	std::cout << " DEBUG, INFO, WARNING or ERROR" << std::endl;
	getline(std::cin, level);
	this_harl.complain(level);
	return (0);
}