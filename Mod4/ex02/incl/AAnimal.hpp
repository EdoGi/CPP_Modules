/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:01:26 by giaco             #+#    #+#             */
/*   Updated: 2022/11/28 01:22:04 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{

	public:
/* 		Would be interesting to put Constructor as protected as we don't want people creating Animal objects directly, 
		but we still want derived classes to be able to use it. */
		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &		operator=( AAnimal const & rhs );

		std::string	getType() const;
		virtual void	makeSound() const = 0;

	protected:

		std::string	type;

};

#endif /* ********************************************************** AANIMAL_H */
