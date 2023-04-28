/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:10 by giaco             #+#    #+#             */
/*   Updated: 2023/04/28 20:57:10 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> BitMap) : _BitExMap(BitMap)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
		this->_BitExMap = rhs._BitExMap;
	return *this;
}

std::map<std::string, float> BitcoinExchange::getMap() const
{
	return this->_BitExMap;
}

void	BitcoinExchange::printMap(std::map<std::string, float> const & BitMap)
{
	std::map<std::string, float>::const_iterator it = BitMap.begin();
	while (it != BitMap.end())
	{
	    std::cout << std::fixed << std::setprecision(2);
		std::cout << it->first << " - " << it->second << std::endl;
		it++;
	}	
}

void  BitcoinExchange::fillBitExMap(BitcoinExchange & Bitcoin)
{
	std::ifstream ifs(FILE_PATH);
	if (!ifs.is_open() || ifs.fail())
        throw std::runtime_error(std::string("Error opening file : ") + FILE_PATH);

	std::string line;
	while (std::getline(ifs, line))
	{
		std::istringstream ss(line);
		std::string date;
		float value;
		std::getline(ss, date, ',');
		ss >> value;
		Bitcoin._BitExMap.insert(std::make_pair(date, value));
	}
	printMap(Bitcoin._BitExMap);
	ifs.close();
}