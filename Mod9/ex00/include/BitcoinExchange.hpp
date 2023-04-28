/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:01 by giaco             #+#    #+#             */
/*   Updated: 2023/04/28 14:43:55 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define SUCCESS 0
# define FAILURE 1

# include "colors.hpp"
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <cstring>
# include <cstdio>
# include <ctime>
# include <map>

class BitcoinExchange
{
	private:
		std::string	_date;
		float		_BitRate;
		
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();
		
		BitcoinExchange(std::string date, float rate);
		
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		std::string getDate() const;
		float		getBitRate() const;
};

#endif