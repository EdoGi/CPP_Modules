/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:41:22 by giaco             #+#    #+#             */
/*   Updated: 2022/12/01 02:26:03 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Useless document"), _issigned(0), _gtosign(150), _gtoexec(150)
{
	std::cout << "Form Default Constructor called : " << BYEL << this->_name << RESET << " | To sign : " << BYEL << this->_gtosign << RESET;
	std::cout << " | To execute : " << BYEL << this->_gtoexec << RESET << std::endl;
}

Form::Form( const Form & src )
{
	std::cout << "Copy Constructor called : Form" << std::endl;
	*this = src;	
}

Form::Form(std::string name, int gtosign, int gtoexec) : _name(name), _issigned(0), _gtosign(gtosign), _gtoexec(gtoexec)
{
	if (gtosign < 1 || gtoexec < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gtosign > 150 || gtoexec > 150 )
		throw Bureaucrat::GradeTooLowException();
	else	
		std::cout << "Form Default Constructor called : " << BYEL << this->_name << RESET << " | To sign : " << BYEL << this->_gtosign << RESET;
		std::cout << " | To execute : " << BYEL << this->_gtoexec << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Destructor called : Form" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	std::cout << "Assignment operator called : Form" << std::endl;
	if (this != &rhs)
	{
		this->_gtoexec = rhs._gtoexec;
		this->_gtosign = rhs._gtoexec;
		this->_issigned = rhs._issigned;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << BBLU << i.getName() << RESET << " form ;";
	o << " grade to sign : " << BBLU << i.getGtoSign() << RESET;
	o << " grade to exec : " << BBLU << i.getGtoExec() << RESET;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Form::beSigned(Bureaucrat const &SignedBy)
{
	int grade_b = SignedBy.getGrade();

	if (grade_b > this->_gtosign)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_issigned = 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const
{
	return (this->_name);
}

int	Form::getGtoSign() const
{
	return (this->_gtosign);
}

int	Form::getGtoExec() const
{
	return (this->_gtoexec);
}

bool	Form::getSigned() const
{
	return (this->_issigned);
}

/* ************************************************************************** */
