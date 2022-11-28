/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:32:13 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 03:59:24 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : type("Random animal")
{
	std::cout << "A new animal is coming to the Ark ⛵️" << std::endl;
}

Animal::Animal( const Animal & src ) : type("Random animal")
{
	std::cout << this->type << " animal is doing exactly the same as " << src.type << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "An animal jumps into the ocean 🌊" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
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

void		Animal::makeSound() const
{
	std::cout << "Unknown animal has done voeux de silence 🙊" << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const
{
	return (this->type);	
}

/* ************************************************************************** */
