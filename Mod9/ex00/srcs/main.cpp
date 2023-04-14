/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:13 by giaco             #+#    #+#             */
/*   Updated: 2023/04/05 01:29:20 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)ac;
	std::ifstream ifs;
	ifs.open(av[1], std::ifstream::in);
	if (!ifs || ifs.is_open() == false || ifs.fail() == true)
	{
		std::cout << "Error with input file" << std::endl;
		ifs.close();
		return 1;
	}
	std::stringstream	buffer;
	buffer << ifs.rdbuf();
	std::cout << buffer.str();
	ifs.close();
	return (0);
}