/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:31:32 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/17 00:30:47 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	level;
	Harl		Harl;
		
	std::cout << "Hello Harl ! Please tell us what's the issue today ?" << std::endl;
	std::cout << "Are you facing any DEBUG, INFO, WARNING or ERROR situation ?" << std::endl;
	std::cout << "If you are tired say DODO" << std::endl;
	while (std::getline(std::cin, level))
	{
		if (level == "DODO")
			break;
		Harl.complain(level);
	}
	return (0);
}