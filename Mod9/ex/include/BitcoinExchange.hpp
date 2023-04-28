/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:01 by giaco             #+#    #+#             */
/*   Updated: 2023/04/28 18:26:19 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define SUCCESS 0
# define FAILURE 1

# include "colors.hpp"
# include <fstream>
# include <sstream>
# include <string>
# include <cstring>
# include <cstdio>
# include <ctime>
# include <map>

typedef struct 	s_Date
{
	int	year;
	int	month;
	int	day;
	
	bool operator<(const s_Date& other) const {
        if (year != other.year) {
            return year < other.year;
        } else if (month != other.month) {
            return month < other.month;
        } else {
            return day < other.day;
        }
    }
}				Date;

class BitcoinExchange
{
private:

public:
	std::map<Date, float> btc_prices;
	std::ifstream ifs;
	float	amount;
	BitcoinExchange();
	~BitcoinExchange();
	
};

#endif