/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:32:13 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 03:49:18 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Oh ! What a cutie ! It's a cat 🐈" << std::endl;
}

Cat::Cat( const Cat & src )
{
	std::cout << this->type << " Cat is doing exactly the same as " << src.type << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
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
	}
	return *this;
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


/* ************************************************************************** */
