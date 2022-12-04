/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:23:39 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 04:42:29 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Base class is A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Base class is B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Base class is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A isA = dynamic_cast<A &>(p);
		std::cout << "Base class is A" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B isB = dynamic_cast<B &>(p);
		std::cout << "Base class is B" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		C isC = dynamic_cast<C &>(p);
		std::cout << "Base class is C" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}		
}

Base * generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	case 2:
		return (new C);
		break;			
	default:
		return (NULL);
		break;
	}

}

int main ()
{
	for (int i = 0; i < 6; i++)
	{	
		Base *NewBase = generate();
		std::cout << "Identify with pointer" << std::endl;
		identify(NewBase);
		std::cout << "Identify with reference" << std::endl;
		identify(NewBase);
		std::cout << std::endl << std::endl;
		delete NewBase;
	}
	return 0;
}