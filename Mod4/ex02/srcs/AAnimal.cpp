/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:32:13 by giaco             #+#    #+#             */
/*   Updated: 2022/11/28 01:23:27 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() : type("Random AAnimal")
{
	std::cout << "A new AAnimal is coming to the Ark ⛵️" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src ) : type("Random AAnimal")
{
	std::cout << this->type << " AAnimal is doing exactly the same as " << src.type << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "An AAnimal jumps into the ocean 🌊" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType() const
{
	return (this->type);	
}

/* ************************************************************************** */
