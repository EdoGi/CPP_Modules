/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:01 by giaco             #+#    #+#             */
/*   Updated: 2023/04/28 20:57:04 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define SUCCESS 0
# define FAILURE 1

# define FILE_PATH "./data.csv"

# include "colors.hpp"
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
// # include <string>
// # include <cstring>
// # include <cstdio>
// # include <ctime>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _BitExMap;
		
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();
		
		BitcoinExchange(std::map<std::string, float> BitMap);
		
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		void	fillBitExMap(BitcoinExchange & Bitcoin);
		void	printMap(std::map<std::string, float> const & BitMap);
		std::map<std::string, float> getMap() const;
};

#endif