/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:01:26 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 23:39:07 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:
/* 		Would be interesting to put Constructor as protected as we don't want people creating Animal objects directly, 
		but we still want derived classes to be able to use it. */
		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );

		std::string	getType() const;
		virtual void	makeSound() const;

	protected:

		std::string	type;

};

#endif /* ********************************************************** ANIMAL_H */
