/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:27:01 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 05:37:11 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Neurones connecting to create a Brain 🧠" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Copy of a 🧠 makes 2 🧠" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Neurones sont cramés.. intelligence niveau 0 🤪" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
		std::cout << "We are both intelligent ⚖️" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const * Brain::getIdeas() const
{
	return (this->_ideas);
}

void				Brain::setIdea(size_t index, std::string arg)
{
	if (index < 100)
		this->_ideas[index] = arg;
}

/* ************************************************************************** */
