/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:13 by giaco             #+#    #+#             */
/*   Updated: 2023/04/28 15:34:02 by giaco            ###   ########.fr       */
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

# define FILE_PATH "./data.csv"

void print_btc_prices(std::map<Date, float> btcsv)
{
	if (btcsv.empty())
		std::cout << "No Map Given" << std::endl;
	else
	{
		std::map<Date, float>::iterator it = btcsv.begin();
		while (it != btcsv.end())
		{
			std::cout <<  it->first.year << '/' << it->first.month << '/' <<  it->first.day << " : " << it->second << std::endl;
			it++;
		}
	}
}

std::ifstream file_opener(const char* file_name)
{
    std::ifstream inputFile(file_name);
    if (!inputFile.is_open() || inputFile.fail()) 
        throw std::runtime_error(std::string("Error opening file ") + FILE_PATH);
    return inputFile;
}

void	csv_parser(BitcoinExchange *btc_exc)
{
	std::string line;
	while (std::getline(btc_exc->ifs, line))
	{
		std::istringstream ss(line);
		std::string dateString;
		float value;
		std::getline(ss, dateString, ',');
		ss >> value;
		
		int year, month, day;
		sscanf(dateString.c_str(), "%d-%d-%d", &year, &month, &day);		
		Date date = {year, month, day};
		btc_exc->btc_prices.insert(std::make_pair(date, value));
	}	
}

bool is_existing_date(int year, int month, int day) {
    tm date;
	memset(&date, 0, sizeof(date));
    date.tm_year = year - 2009;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    time_t time = mktime(&date);

    return memcmp(&date, localtime(&time), sizeof(tm)) == 0;
}

void	input_parser(BitcoinExchange *btc_exc)
{
	std::string input;
	while (std::getline(btc_exc->ifs, input))
	{
		std::istringstream ss(input);
		std::string checkDatestr;
		std::getline(ss, checkDatestr, '|');
		
		// std::cout << btc_exc->amount << std::endl <<std::endl;
		
		int year, month, day;
		sscanf(checkDatestr.c_str(), "%d-%d-%d", &year, &month, &day);
		if (is_existing_date(year, month, day) && year >= 2009 && year <= 2022)
		{
			Date checkDate = {year, month, day};
			ss >> btc_exc->amount;
			if (btc_exc->amount < 0)
				std::cerr << "Invalid negative amount" << std::endl;
			else if (btc_exc->amount >= INT_MAX)
				std::cerr << "Invalid max size" << std::endl;
			else
			{
				// std::cout << "Date is : " << checkDate.year << '-' << checkDate.month << '-' << checkDate.day << " and amount is " << btc_exc->amount << std::endl;
				std::map<Date, float>::iterator it = btc_exc->btc_prices.begin();
				while (it != btc_exc->btc_prices.end())
				{
					if (checkDate.year == it->first.year && checkDate.month == it->first.month && checkDate.day == it->first.day)
					{
						std::cout << checkDate.year << '-' << checkDate.month << '-' << checkDate.day << " => " << btc_exc->amount << " = " << (it->second * btc_exc->amount) << std::endl;
						break;
					}
					it++;
				}
				if (it == btc_exc->btc_prices.end())
				{
					btc_exc->btc_prices.insert(std::pair<Date, float>(checkDate, 0));
					it = btc_exc->btc_prices.find(checkDate);	
					it--;	
					float prev = it->second;
					it++;
					it->second = prev;
					std::cout << it->first.year << '-' << it->first.month << '-' << it->first.day << " => " << btc_exc->amount << " = " << (it->second * btc_exc->amount) << std::endl;
				}	
			}
		}
		else
		{
			std::cout << "Not a valid date" << std::endl;
			continue;
		}	
	}
	btc_exc->ifs.close();			
}

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Error : Correct usage ./btc <file>" << std::endl;
		return FAILURE;
	}
	
	BitcoinExchange btc_exc;
	try
	{
		btc_exc.ifs = file_opener(FILE_PATH);
		csv_parser(&btc_exc);
		btc_exc.ifs.close();
	}
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return FAILURE;
    }
	
	try
	{
		btc_exc.ifs = file_opener(av[1]);
		input_parser(&btc_exc);
		btc_exc.ifs.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return FAILURE;
	}
	return (0);
}
