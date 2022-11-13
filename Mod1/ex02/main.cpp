/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:39:41 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 03:47:11 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "str address is : " << &str << std::endl;
	std::cout << "PTR address is : " << stringPTR << std::endl;
	std::cout << "REF address is : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "str means : " << str << std::endl;
	std::cout << "PTR means : " << *stringPTR << std::endl;
	std::cout << "REF means : " << stringREF << std::endl;

	return 0;
}