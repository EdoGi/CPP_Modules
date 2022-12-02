/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:18:38 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/02 07:41:27 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern( const Intern & src )
{
	std::cout << "Copy Constructor called : Intern" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "Destructor called : Intern" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	std::cout << "Assignment operator called : Intern" << std::endl;
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << BGRN << " Intern " << RESET;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form	*createForm(std::string name, std::string target)
{
	int i;
	Form *NewForm;
	
	std::string	Forms[3] = {"RobotomyRequest", "PresidentialPardon", "ShrubberyCreation"};
	for (i = 0; i <= 3; i++)
	{
		if (name == Forms[i])
			break;
	}
	switch (i) {
		case 0:
			NewForm = new RobotomyRequestForm(target);
			break;
		case 1:
			NewForm = new PresidentialPardonForm(target);
			break;
		case 2:
			NewForm = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::AbsentFormException();
			break;
	}
	return (NewForm);
}

Form	*Intern::makeForm(std::string formName, std::string targetName) const
{
	Form *NewForm;
	
	try
	{
		NewForm = createForm(formName, targetName);
	}
	catch(const std::exception &e)
	{
		std::cout << "Intern couldn't make this forme because : " << BWHT;
		// std::cerr << e.what() << RESET << std::endl;
		throw Intern::AbsentFormException();
	}
	return (NewForm);
}

/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char* Intern::AbsentFormException::what() const throw()
{
	return ("This form doesn't exist");
}

/* ************************************************************************** */