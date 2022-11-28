/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:01:45 by giaco             #+#    #+#             */
/*   Updated: 2022/11/28 01:24:36 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	std::cout << "It's actually a beautiful Golden Retriever 🦮" << std::endl;
	this->_Brain = new Brain();
}

Dog::Dog( const Dog & src ) : AAnimal(src)
{
	std::cout << "It's a Dog Copy" << std::endl;
	this->type = src.type;
	this->_Brain = new Brain(*src.getBrain());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->_Brain;
	std::cout << "The Golden R loves to swim 🐶" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		if (this->_Brain)
			delete this->_Brain;
		this->_Brain = new Brain(*rhs.getBrain());		
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Dog::makeSound() const
{
	std::cout << "Wonderful dog says : Ouaf Ouaf 🐕🎶" << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain * Dog::getBrain() const
{
	return (this->_Brain);
}

/* ************************************************************************** */
