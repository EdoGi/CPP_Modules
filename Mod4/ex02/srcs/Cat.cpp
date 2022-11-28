/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:32:13 by giaco             #+#    #+#             */
/*   Updated: 2022/11/28 01:24:49 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	std::cout << "Oh ! What a cutie ! It's a cat 🐈" << std::endl;
	this->_Brain = new Brain();
}

Cat::Cat( const Cat & src ) : AAnimal(src)
{
	std::cout << this->type << " Cat is doing exactly the same as " << src.type << std::endl;
	this->type = src.type;
	this->_Brain = new Brain(*src.getBrain());
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->_Brain;
	std::cout << "A Cat jumps into the ocean 🙀" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		if (this->_Brain)
			delete this->_Brain;
		this->_Brain = new Brain(*rhs.getBrain());	
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Cat::makeSound() const
{
	std::cout << "Beautiful cat says : Miaou Miaou 😺🎶" << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain * Cat::getBrain() const
{
	return (this->_Brain);
}

/* ************************************************************************** */
