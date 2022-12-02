/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:46:47 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/02 04:42:04 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("Unnamed")
{
	std::cout << "RobotomyRequestForm Default Constructor called.";
	std::cout << BWHT << " Target : " + this->_target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	std::cout << "Copy Constructor called : RobotomyRequestForm" << std::endl;
	*this = src;	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Parametric Constructor called.";
	std::cout << BWHT << " Target : " + target << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called : RobotomyRequestForm" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/* Fait des bruits de perceuse. Ensuite, informe que la <target> a été robotomisée
avec succès 50% du temps. Dans le cas contraire, informe que l’opération a échoué. */
void	RobotomyRequestForm::execute(void) const
{
	std::cout << BWHT << "PERCEUSE NOOOOOOOOOOOOIIIIISE 🪛🔊" << std::endl;
	/* initialize random seed: */
	srand (time(0));
 	/* 50% de chance*/
	if(rand() % 2)
	{
		std::cout << BLUE << this->_target + " has been robotomised !" << RESET << std::endl;
	} 
	else 
	{
		std::cout << BLUE << "Robotomy failed on " + this->_target << std::endl;
	}
}

/* ************************************************************************** */

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << "Assignment operator called : RobotomyRequestForm" << std::endl;
	if ( this != &rhs )
		this->_target = rhs.getTarget();
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

/* ************************************************************************** */