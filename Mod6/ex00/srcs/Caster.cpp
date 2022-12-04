/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Caster.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:23:37 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 02:13:53 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Caster.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Caster::Caster()
{
	std::cout << GREEN << "Default Constructor" << RESET << " Caster called" << std::endl;
}

Caster::Caster(const Caster & src)
{
	std::cout << GREEN << "Copy Constructor" << RESET << " Caster called" << std::endl;
	*this = src;
}

Caster::Caster(const char *value) : _value(value), _isprint(true), _validChar(true), _validInt(true)
{
	std::cout << GREEN << "Parametric Constructor" << RESET << " Caster called with ";
	std::cout << BGRN << _value << RESET << std::endl;
	init_caster();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Caster::~Caster()
{
	std::cout << RED << "Destructor" << RESET << " Caster called" << std::endl;		
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Caster &				Caster::operator=( Caster const & rhs )
{
	std::cout << "Caster" << BLUE << " Assign Overload" << RESET << std::endl;
	if ( this != &rhs )
	{
		this->_char = rhs._char;
		this->_double = rhs._double;
		this->_float = rhs._float;
		this->_int = rhs._int;
		this->_value = rhs._value;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool	Caster::isChar(const char *value)
{
	if (!value[1])
	{
		if (std::isprint(value[0]) && !std::isdigit(value[0]))
		{
			this->_type = CHAR;
			this->_char = value[0];
			return (true);
		}
	}
	return (false);
}

bool	Caster::isInt(const char *value)
{
	char	*endptr = NULL;
	long	lvalue = strtol(value, &endptr, 10);
	
	if (!*endptr && lvalue >= INT_MIN && lvalue <= INT_MAX)
	{
		this->_type = INT;
		this->_int = static_cast<int>(lvalue);
		return (true);		
	}
	return (false);
}

bool	Caster::isFloat(const char *value)
{
	char	*endptr = NULL;
	float	fvalue = strtof(value, &endptr);
	
	if (*endptr != 'f' || *(endptr + 1))
		return (false);
	this->_type = FLOAT;
	this->_float = fvalue;
	return (true);		
}

bool	Caster::isDouble(const char *value)
{
	char	*endptr = NULL;
	double	dvalue = strtod(value, &endptr);
	
	if (!*endptr)
	{
		this->_type = DOUBLE;
		this->_double = dvalue;
		return (true);		
	}
	return (false);
}

void	Caster::castingcheck()
{
	if (this->_double < INT_MIN || this->_double > INT_MAX \
		|| std::isnan(this->_double) || std::isinf(this->_double))
	{
		this->_validChar = false;
		this->_validInt = false;	
	}
	else if (this->_double < CHAR_MIN || this->_double > CHAR_MAX)
		this->_validChar = false;
	else if (!std::isprint(this->_char))
		this->_isprint = false;
}

void	Caster::casting()
{
	switch (this->_type)
	{
		case CHAR:
			this->_int = this->_char;
			this->_float = this->_char;
			this->_double = this->_char;
			break;
		case INT:
			this->_char = static_cast<char>(this->_int);
			this->_float = this->_int;
			this->_double = this->_int;
			break;
		case FLOAT:
			this->_char = static_cast<char>(this->_float);
			this->_int = static_cast<int>(this->_float);
			this->_double = static_cast<double>(this->_float);
			break;
		case DOUBLE:
			this->_char = static_cast<char>(this->_double);
			this->_int = static_cast<int>(this->_double);
			this->_float = static_cast<float>(this->_double);
			break;
		default:
			this->_validChar = false;
			this->_validInt = false;
			this->_float = NAN;
			this->_double = NAN;		
			break;
	}
	castingcheck();
}

void	Caster::init_caster()
{
		if (!isChar(this->_value) && !isInt(this->_value) \
			&& !isFloat(this->_value) && !isDouble(this->_value))
				this->_type = INVALID;
		this->casting();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Caster::displayer(Caster &ref) const
{
	std::cout << std::fixed << std::setprecision(1);
	
	std::cout << "Char : ";
	if (ref._isprint == false)
		std::cout << "Non printable" << std::endl;		
	else if (ref._validChar == false)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << "'" << ref._char << "'" << std::endl;		
	std::cout << "Int : ";
	if (ref._validInt == false)
		std::cout << "impossible" << std::endl;		
	else 
		std::cout << ref._int << std::endl;		
	std::cout << "Float : " << ref._float << "f" << std::endl;
	std::cout << "Double : " << ref._double << std::endl;
}

/* ************************************************************************** */