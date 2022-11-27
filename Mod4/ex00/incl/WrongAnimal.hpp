/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:01:29 by giaco             #+#    #+#             */
/*   Updated: 2022/11/27 04:07:24 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:
/* 		Would be interesting to put Constructor as protected as we don't want people creating WrongAnimal objects directly, 
		but we still want derived classes to be able to use it. */
		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );

		std::string	getType() const;
		void	makeSound() const;

	protected:

		std::string	type;

};

#endif /* ********************************************************** WRONGANIMAL_H */
