/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:04 by giaco             #+#    #+#             */
/*   Updated: 2022/12/05 14:02:43 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::cout << BWHT<< "================= Int Array ===============" << RESET << std::endl;
	int intArray[5] = {0, 1, 2, 3, 4};
	iter<int>(intArray, 5, &display);		// Explicit template instanciation
	iter(intArray, 5, &increment);		// Implicit template instanciation
	std::cout << "/* After incrementation */" << std::endl;
	iter(intArray, 5, display);
	
	std::cout << BWHT<< "\n================= Float Array ===============" << RESET << std::endl;
	float floatArray[3] = {0.42f, 1.42f, 2.42f};
	iter<float>(floatArray, 3, display);		// Explicit template instanciation
	iter(floatArray, 3, increment);			// Implicit template instanciation
	std::cout << "/* After incrementation */" << std::endl;
	iter(floatArray, 3, display);

	std::cout << BWHT<< "\n================= String Array ===============" << RESET << std::endl;
	std::string	strArray[3] = {"Salut", "les", "nazes"};
	iter<std::string>(strArray, 3, display);		// Explicite template instanciation

	std::cout << BWHT<< "\n================= Char to Upper ===============" << RESET << std::endl;
	char charArray[28] = "bonjour mes petits loukoums";
	std::cout << charArray << '\n';
	iter<char>(charArray, strlen(charArray), toupper);		// Explicit template instanciation
	std::cout << charArray << '\n';

	return 0;
}