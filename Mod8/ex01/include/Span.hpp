/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:43:53 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/06 08:26:40 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "colors.hpp"
# include <iostream>
# include <set>
# include <vector>
# include <string>
# include <cstdlib>

class Span
{

	public:

		Span();
		Span( Span const & src );
		~Span();

		Span(unsigned int N);

		Span &		operator=( Span const & rhs );

		void	addNumber(int value);
		void	addPlageNumber(unsigned int plage);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void	print_table() const;
		
	private:

		unsigned int		_N;
		std::multiset<int>	table;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */