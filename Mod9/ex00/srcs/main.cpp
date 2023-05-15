/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:13 by giaco             #+#    #+#             */
/*   Updated: 2023/05/15 15:11:10 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	printBitVal(std::string const date, float const amount, BitcoinExchange const & BitMap)
{
	std::map<std::string, float> CurrentMap = BitMap.getMap();
	std::map<std::string, float>::iterator it = CurrentMap.find(date);
	if (it == CurrentMap.end())
	{
		CurrentMap.insert(std::pair<std::string, float>(date, 0));
		it = CurrentMap.find(date);
		it--;
	}
	std::cout << date << " => " << amount << " = " << (amount * it->second) << std::endl;
}

bool	checkAmount(float amount)
{
	if (amount < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return FAILURE;
	}
	if (amount > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}

bool	checkDate(std::string date)
{
	int year, month, day;
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
	{
		std::cerr << "Error: Invalid date format => " << date << std::endl;
		return FAILURE;
	}	// if (memcmp(&tdate, localtime(&time), sizeof(tm)))

	tm tdate;
	memset(&tdate, 0, sizeof(tdate));
	tdate.tm_year =  year - 1900;
	tdate.tm_mon = month - 1;
	tdate.tm_mday = day;

	time_t time = mktime(&tdate);
	tm *tmp = localtime(&time);
	if (tmp->tm_year == year - 1900 && tmp->tm_mon == month - 1 && tmp->tm_mday == day)
		return SUCCESS;
	else
	{
		std::cerr << "Error: Invalid date => " << date << std::endl;
		return FAILURE;	
	}
}

bool	checkInput(std::string const & line, std::string & date, float & amount)
{
	std::istringstream ss(line);
		
	std::getline(ss, date, '|');
	if (date.empty())
	{
		std::cerr << "Error: Bad input, expected format : 'date | value'" << std::endl;
		return FAILURE;
	}
	if (!isdigit(date[0]))
		return FAILURE;
	std::size_t space = date.find_last_not_of(" ");
	if (space != std::string::npos)
		date = date.substr(0, space + 1);
	if (checkDate(date))
		return FAILURE;
	ss >> amount;
	if (checkAmount(amount))
		return FAILURE;
	return SUCCESS;
}

void	findBitVal(std::string const filename, BitcoinExchange const & Bitcoin)
{
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open() || ifs.fail() || ifs.peek() == EOF)
    {
        ifs.close();
		throw std::runtime_error(std::string("Error opening file : ") + filename);
	}
	std::string line;
	std::string date;
	float amount;
	while (std::getline(ifs, line))
	{
		if (checkInput(line, date, amount))
			continue;
		printBitVal(date, amount, Bitcoin);
	}
	// printMap(Bitcoin._BitExMap);
	ifs.close();
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