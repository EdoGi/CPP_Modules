/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:11:57 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/17 02:47:57 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char ** av)
{
	std::string level;
	Harl		harl;

	if (ac == 2)
	{	
		level = av[1];
		harl.complain(level);
	}
	return (0);
}