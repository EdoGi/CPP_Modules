/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:46:50 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/02 08:08:54 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("Unnamed")
{
	std::cout << "ShrubberyCreationForm Default Constructor called.";
	std::cout << BWHT << " Target : " + this->_target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
	std::cout << "Copy Constructor called : ShrubberyCreationForm" << std::endl;
	*this = src;	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Parametric Constructor called.";
	std::cout << BWHT << " Target : " + target << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called : ShrubberyCreationForm" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(void) const
{
	std::string		filename = _target;
	std::ofstream	ofs;
	
	filename.append("_shrubbery");
	try
	{
		ofs.open(filename.c_str(), std::ofstream::out);
		if (!ofs || ofs.fail())
			throw std::exception();
		ofs << "         wWWWw               wWWWw        " << std::endl;
		ofs << "   vVVVv (___) wWWWw         (___)  vVVVv " << std::endl;
		ofs << "   (___)  ~Y~  (___)  vVVVv   ~Y~   (___) " << std::endl;
		ofs << "    ~Y~    |    ~Y~   (___)    |/    ~Y~  " << std::endl;
		ofs << "     |     |/    | /   ~Y~/    |      |/  " << std::endl;
		ofs << "   \\|// \\|// \\|/// \\|//  \\|//  \\|///" << std::endl;
		ofs << "  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
		ofs.close();
	}
	catch (std::exception &e)
	{
		std::cout << "Error with output file" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

/* ************************************************************************** */

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "Assignment operator called : ShrubberyCreationForm" << std::endl;
	if ( this != &rhs )
		this->_target = rhs.getTarget();
	return *this;
}

/* ************************************************************************** */