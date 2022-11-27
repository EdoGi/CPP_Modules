/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:59:48 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 04:16:45 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "Ah ! A Second WrongCat 🐈" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << this->type << " WrongCat is copy of " << src.type << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat fly to the sky 🕊️" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		WrongCat::makeSound() const
{
	std::cout << "New wrongcat says : Never gonna talk 😺🎶" << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
