/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:46:23 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/02 07:45:09 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << BWHT << "\n================== 💼 Bureaucrat - 📝 Form - 🖨️  Intern  ====================" << RESET << std::endl;
	std::cout << "------------------ Constructors ------------------" << std::endl;
	Bureaucrat	JeanMierre("JeanMierre", 5);
	Intern		Hugo;
	Form		*form;
	
	std::cout << std::endl;
	std::cout << "\n------------------ 🌳 Shrubbery Creation Forms 🌳 ------------------" << std::endl;
	try
	{
		form = Hugo.makeForm("ShrubberyCreation", "forest");
		std::cout << *form << std::endl;
		JeanMierre.signForm(*form);
		JeanMierre.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << RESET << std::endl;
	}
	std::cout << "\n------------------ 🤖 Robotomy Creation Forms 🤖 ------------------" << std::endl;
	try
	{
		form = Hugo.makeForm("RobotomyRequest", "Wall-E");
		std::cout << *form << std::endl;
		JeanMierre.signForm(*form);
		JeanMierre.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << RESET << std::endl;
	}

	std::cout << "\n------------------ 👨‍💼 Presidental Creation Forms 👨‍💼 ------------------" << std::endl;
	try
	{
		form = Hugo.makeForm("PresidentialPardon", "Trump");
		std::cout << *form << std::endl;
		JeanMierre.signForm(*form);
		JeanMierre.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << RESET << std::endl;
	}

	std::cout << "\n------------------ Wrong Form ------------------" << std::endl;
	try
	{
		form = Hugo.makeForm("WrongForm", "Johny");
		std::cout << *form << std::endl;
		JeanMierre.signForm(*form);
		JeanMierre.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << "------------------ Destructors ------------------" << std::endl;
	return (0);
}