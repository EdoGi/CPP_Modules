/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:41:44 by egiacomi          #+#    #+#             */
/*   Updated: 2023/05/01 23:39:06 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN::RPN(std::string eq) : _rpn(eq)
{
	std::istringstream iss(eq);
	std::string token;
	while (iss >> token)
	{
		if (token.size() > 1)
			throw std::runtime_error(std::string("Error : operands must be only one digit"));
		if (isdigit(token[0]))			
			this->_polish.push(atoi(token.c_str()));
		else
			calculOperator(token);
	}
	if (this->_polish.size() != 1)
        throw std::runtime_error(std::string("Error invalid expression : No or multiple operands left"));
	else
		_result = this->_polish.top();
}

RPN & RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
		this->_polish = rhs._polish;
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculOperator(std::string token)
{
	int a, b;
	
	if (this->_polish.size() < 2)
        throw std::runtime_error(std::string("Error invalid expression : Operator with less than 2 operands"));
	
	b = this->_polish.top();
	this->_polish.pop();
	a = this->_polish.top();
	this->_polish.pop();
	switch (token[0])
	{
		case '+':
			this->_polish.push(a + b);
			break;
		case '-':
			this->_polish.push(a - b);
			break;
		case '*':
			this->_polish.push(a * b);
			break;
		case '/':
			if (b == 0)
        		throw std::runtime_error(std::string("Error calculation : division by 0 impossible"));
			this->_polish.push(a / b);
			break;					
		default:
			break;
	}
}

std::string RPN::getRPN() const
{
	return this->_rpn;
}

int RPN::getResult() const
{
	return this->_result;
}

std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	o << "RPN : " << i.getRPN() << "\nResult : " << i.getResult() << std::endl;
	return o;
}
