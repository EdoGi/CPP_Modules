/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:27:16 by giaco             #+#    #+#             */
/*   Updated: 2022/12/03 16:39:21 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << BWHT << "============ Test Too Low Grade to construct ============" << RESET << std::endl;
	try 
	{
		Bureaucrat Kevin("Kevin", 160);
	}
	catch (std::exception &e)		// Could specify what kind of exception to catch, ex : Bureaucrat::GradeTooLowException& e
	{
		  std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << BWHT << "\n============ Test Too High Grade to construct ============" << RESET << std::endl;
	try 
	{
		Bureaucrat Dwight("Dwight", 0);
	}
	catch (std::exception &e)		// Could specify what kind of exception to catch, ex : Bureaucrat::GradeTooHighException& e
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << BWHT << "============ Basic Test  ============" << RESET << std::endl;
	try 
	{
		Bureaucrat	Pam("Pam", 70);
		std::cout << Pam << std::endl;
		Pam.increment();
		std::cout << Pam << std::endl;
	}
	catch (std::exception &e)
	{
		  std::cerr << BRED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << BWHT << "============ Test Demote / Promote  ============" << RESET << std::endl;
	Bureaucrat	Random;
	
	std::cout << Random << std::endl;
	try 
	{
		std::cout << BWHT << "Trying to demote Jean-Jacques" << RESET << std::endl;
		Random.decrement();					// Asap my try "returns" a throw it goes to the 'Catch block'
		std::cout << Random << std::endl;	// This line won't be executed 
	}
	catch (std::exception &e)
	{
		  std::cerr << BRED << e.what() << RESET << std::endl;
	}

	try 
	{
		std::cout << BWHT << "Trying to promote Jean-Jacques" << RESET << std::endl;
		Random.increment();
		std::cout << Random << std::endl;
	}
	catch (std::exception &e)
	{
		  std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return (0);
}
