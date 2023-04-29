/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:41:47 by egiacomi          #+#    #+#             */
/*   Updated: 2023/04/29 05:10:26 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define SUCCESS 0
# define FAILURE 1

# include <iostream>
// # include <iomanip>
// # include <fstream>
// # include <sstream>
# include <cstring>
// # include <ctime>
// # include <cctype>
# include <stack>

class RPN
{
	private:
		std::stack<int> equation;
		int				a;
		int				b;
		
	public:
		RPN();
		RPN(RPN const & src);
		RPN(std::string eq);
		~RPN();
		RPN & operator=(RPN const & rhs);
};

RPN::RPN()
{
}

RPN::RPN(std::string eq)
{
}

RPN::~RPN()
{
}

#endif