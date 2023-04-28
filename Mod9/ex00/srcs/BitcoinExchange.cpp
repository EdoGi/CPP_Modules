/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:10 by giaco             #+#    #+#             */
/*   Updated: 2023/04/28 14:49:35 by giaco            ###   ########.fr       */
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

BitcoinExchange::BitcoinExchange(std::string date, float rate) : _date(date), _BitRate(rate)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		this->_date = rhs._date;
		this->_BitRate = rhs._BitRate;
	}
	return *this;
}

std::string	BitcoinExchange::getDate() const
{
	return this->_date;
}

float	BitcoinExchange::getBitRate() const
{
	return this->_BitRate;	
}