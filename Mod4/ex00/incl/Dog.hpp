/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:01:33 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 04:01:34 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
#include "Animal.hpp"

class Dog : public Animal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator=( Dog const & rhs );

/*	Could be written with or without the virtual HERE, but in C++11 you would prefer usign override (implicitly virtual) to make sure it overide 
	https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/	*/
		virtual void	makeSound() const;

};

#endif /* ********************************************************** DOG_H */
