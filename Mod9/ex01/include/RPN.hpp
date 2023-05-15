/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:41:47 by egiacomi          #+#    #+#             */
/*   Updated: 2023/05/15 17:03:32 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define SUCCESS 0
# define FAILURE 1

# include <iostream>
// # include <iomanip>
// # include <fstream>
# include <cstdlib>
# include <sstream>
# include <cstring>
// # include <ctime>
# include <stack>

class RPN
{
	private:
		std::stack<int> _polish;
		std::string		_rpn;
		int				_result;
		// int				a;
		// int				b;
		
	public:
		RPN();
		RPN(RPN const & src);
		~RPN();
		
		RPN(std::string polish);
		
		RPN & operator=(RPN const & rhs);
		
		std::string getRPN() const;
		int getResult() const;
		void calculOperator(std::string token);
};

std::ostream & operator<<( std::ostream & o, RPN const & i );

#endif