/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:43:40 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/06 08:27:00 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
	std::cout << "Span : " << BGRN << "Default Constructor" << RESET << std::endl;
}

Span::Span( const Span & src )
{
	std::cout << "Span : " << BGRN << "Copy Constructor" << RESET << std::endl;
	*this = src;
}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Span : " << BGRN << "Parametric Constructor" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	std::cout << "Span : " << BCYN << "Destructor" << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	std::cout << "Span : " << BGRN << "Assignment Overload" << RESET << std::endl;
	if ( this != &rhs )
	{
		this->_N = rhs._N;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

	void	Span::addNumber(int value)
	{
		if (this->table.size() < this->_N)
			this->table.insert(value);
		else
			throw std::runtime_error("Maximum size reached : addNumber impossible");
	}

	void	Span::addPlageNumber(unsigned int plage)
	{
		srand(time(NULL));
		
		for (unsigned int i = 0; i < plage; i++)
				this->addNumber((rand() % 500) + 1);	
	}
	
	void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
	{
		if (this->table.size() + std::distance(begin, end) > this->_N)
			throw std::runtime_error("Maximum size reach : addRange Blocked");
		
		this->table.insert(begin, end);
	}

	unsigned int	Span::shortestSpan() const
	{
		if (this->table.empty() || this->table.size() < 2)
			throw std::runtime_error("Not enough value to check for a Span !");
		int	shortspan = this->longestSpan();
		unsigned long	num = 1;
		std::multiset<int>::iterator it = this->table.begin();
		while (it != this->table.end() && num < this->table.size())
		{
			int val = *it;
			it++;
			if (*it - val < shortspan)
				shortspan = (*it - val);
			num++;
		}
		return (shortspan);
	}
	
	unsigned int	Span::longestSpan() const
	{
		if (this->table.empty() || this->table.size() < 2)
			throw std::runtime_error("Not enough value to check for a Span !");
		std::multiset<int>::iterator itbeg = this->table.begin();
		std::multiset<int>::reverse_iterator itlast = this->table.rbegin();
		return (*itlast - *itbeg);
	}
		
	void	Span::print_table() const
	{
		std::multiset<int>::iterator it = this->table.begin();
		std::cout << "SIZE IS : " << this->table.size() << '\n';
		std::cout << BWHT  <<"| " << RESET;
		while (it != this->table.end())
		{
			std::cout << *it << BWHT << " | " << RESET;
			++it;
		}
		try
		{
			std::cout << BYEL << "\nShortest Span is : " << BLUE << this->shortestSpan() << RESET;
			std::cout << BYEL << "\nLongest Span is : " << BLUE << this->longestSpan() << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		std::cout << std::endl;
	}
 
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */