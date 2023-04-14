/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:13 by giaco             #+#    #+#             */
/*   Updated: 2023/04/14 17:32:21 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	TODO :
	- Read CSV
	- Tokenise CSV in Map Container (Date | Value)
	- Read Input.txt
	- Tokenise Input.txt (Date | Amount)
	- Count Value (Amount * Value)
	- Display result
*/

#include "BitcoinExchange.hpp"

void	fake(std::map<std::string, double> fake_map, std::string)
{
	fake_map.insert()
}

int main(int ac, char **av)
{
	(void)ac;
	
	std::ifstream inputFile("data.csv");
	if (!inputFile || !inputFile.is_open() || inputFile.fail()) 
	{
    	std::cerr << "Error opening file\n";
    	return 1;
	}

	std::string line;
	std::map<std::string, double> btc_prices;
	while (std::getline(inputFile, line))
	{
		std::istringstream ss(line);
		std::string token;
		while (std::getline(ss, token, ','))
		{
			// Split Date in YYYY-MM-DD : Key
		}
		// Map
	}

	inputFile.close();
	// std::ifstream ifs;
	// ifs.open(av[1], std::ifstream::in);
	// if (!ifs || ifs.is_open() == false || ifs.fail() == true)
	// {
	// 	std::cout << "Error with input file" << std::endl;
	// 	ifs.close();
	// 	return 1;
	// }
	// std::stringstream	buffer;
	// buffer << ifs.rdbuf();
	// std::cout << buffer.str();
	// ifs.close();
	// return (0);
}