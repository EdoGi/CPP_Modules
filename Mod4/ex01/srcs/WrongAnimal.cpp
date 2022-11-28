/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:59:32 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 04:07:11 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : type("Fake Animal")
{
	std::cout << "This Animal is a FAKE ❗️⚠️⚠️⚠️❗️" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) : type("Fake Animal")
{
	std::cout << this->type << " FAKE Animal try to copulate with " << src.type << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "Hopefully, the Fake disapears ☁️" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
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

void		WrongAnimal::makeSound() const
{
	std::cout << "Fake is doing les sirènes de la Police 🚔" << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType() const
{
	return (this->type);	
}

/* ************************************************************************** */
