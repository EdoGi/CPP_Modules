/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:41:22 by giaco             #+#    #+#             */
/*   Updated: 2022/12/02 08:10:21 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Useless document"), _issigned(0), _gtosign(150), _gtoexec(150)
{
	std::cout << "Form Default Constructor called : " << BYEL << this->_name << RESET << std::endl;
	std::cout << "- To sign : " << BYEL << this->_gtosign << RESET << std::endl;
	std::cout << "- To execute : " << BYEL << this->_gtoexec << RESET << std::endl;
	if (this->_issigned)
		std::cout << "- Is signed : " << BYEL << "YES" << RESET << std::endl;
	else
		std::cout << "- Is signed : " << BYEL << "NO" << RESET << std::endl;
}

Form::Form( const Form & src ) :
	_name(src._name), _issigned(src._issigned), _gtosign(src._gtosign), _gtoexec(src._gtoexec)
{
	std::cout << "Copy Constructor called : Form" << std::endl;
	*this = src;	
}

Form::Form(std::string const name, int const gtosign, int const gtoexec) : _name(name), _issigned(0), _gtosign(gtosign), _gtoexec(gtoexec)
{
	std::cout << "Form Parametric Constructor called : " << BYEL << this->_name << RESET << std::endl;
	if (gtosign < 1 || gtoexec < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gtosign > 150 || gtoexec > 150 )
		throw Bureaucrat::GradeTooLowException();
	else	
	{
		std::cout << "- To sign : " << BYEL << this->_gtosign << RESET << std::endl;
		std::cout << "- To execute : " << BYEL << this->_gtoexec << RESET << std::endl;
		if (this->_issigned)
			std::cout << "- Is signed : " << BYEL << "YES" << RESET << std::endl;
		else
			std::cout << "- Is signed : " << BYEL << "NO" << RESET << std::endl;
	}
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
		this->_issigned = rhs._issigned;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << BBLU << i.getName() << RESET << " form ";
	o << "| Grade to Sign : " << BBLU << i.getGtoSign() << RESET;
	o << " | Grade to Exec : " << BBLU << i.getGtoExec() << RESET;
	if (i.getSigned())
		std::cout << " | Is signed : " << BBLU << "YES" << RESET;
	else
		std::cout << " | Is signed : " << BBLU << "NO" << RESET;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Form::beSigned(Bureaucrat const &SignedBy)
{
	int grade_b = SignedBy.getGrade();
	
	if (this->_issigned)
		throw Form::AlreadySignedException();
	else if (grade_b > this->_gtosign)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_issigned = 1;
}

void	Form::execute(Bureaucrat const & executor) const
{
	int grade_b = executor.getGrade();

	if (this->_issigned)
	{
		if (grade_b > this->_gtoexec)
			throw Bureaucrat::GradeTooLowException();
		else
			execute();
	}
	else
		throw Form::UnsignedException();
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

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char* Form::UnsignedException::what() const throw()
{
	return ("Form was not Signed before Execution trial");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("Form has already been signed");
}

/* ************************************************************************** */
