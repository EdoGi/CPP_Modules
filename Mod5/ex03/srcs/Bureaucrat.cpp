/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:27:10 by giaco             #+#    #+#             */
/*   Updated: 2022/12/02 08:09:54 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called : " << BCYN << this->_name << RESET << " Bureaucrat with grade " << BCYN << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	std::cout << "Copy Constructor called : Bureaucrat" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else	
		std::cout << "Bureaucrat Parametric Constructor called : Bureaucrat named " << BCYN << name << RESET << " with grade " << BCYN << this->_grade << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called : Bureaucrat" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "Assignment operator called : Bureaucrat" << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << BGRN << i.getName() << RESET << ", Bureaucrat grade : " << BPUR << i.getGrade() << RESET;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Bureaucrat::increment(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrement(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed Form " + form.getName() << RESET << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << RED << this->_name << " couldn't sign Form " + form.getName();
		std::cerr << " because " << BRED << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << this->_name << " has executed Form " + form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->_name << " couldn't execute Form " + form.getName();
		std::cerr << " because " << BRED << e.what() << RESET << std::endl;
	}
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

int			Bureaucrat::getGrade() const
{
	return(this->_grade);
}

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low ! (smaller than 1)");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High ! (bigger than 150)");
}

/* ************************************************************************** */
