/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:13 by giaco             #+#    #+#             */
/*   Updated: 2023/04/28 20:49:19 by egiacomi         ###   ########.fr       */
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

	- Check error and special cases (non existing date, unpossible date, ...)
*/

#include "BitcoinExchange.hpp"

void	findBitVal(std::string filename, BitcoinExchange const & Bitcoin)
{
	std::ifstream ifs(filename.c_str());
	(void) Bitcoin;
}


int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Error : Correct usage ./btc <file>" << std::endl;
		return FAILURE;
	}
	
	try
	{
		BitcoinExchange Bitcoin;
		Bitcoin.fillBitExMap(Bitcoin);
		findBitVal(av[1], Bitcoin);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return FAILURE;
	}
	
	return SUCCESS;
}