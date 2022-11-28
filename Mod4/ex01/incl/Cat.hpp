/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:00:21 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 23:42:29 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &		operator=( Cat const & rhs );

/*	Could be written with or without the virtual HERE, but in C++11 you would prefer usign override (implicitly virtual) to make sure it overide 
	https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/	*/
		virtual void	makeSound() const;
	
		Brain * getBrain() const;
		
	private :

		Brain * _Brain;

};

#endif /* ********************************************************** CAT_H */
		// assign._Brain->setIdea(0, "Nonono");
