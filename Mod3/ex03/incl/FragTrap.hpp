/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:57:08 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/24 04:42:24 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	private :

	public :
		
		/* DEFAULT & COPY CONSTRUCTORS + DESTRUCTOR */
		FragTrap(void);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		
		/* PARAMETRIC CONSTRUCTOR */
		FragTrap(std::string const name);
		
		/* ASSIGNEMENT OPERATOR OVERLOAD */
		FragTrap & operator=(FragTrap const & rhs);

		void attack(const std::string& target);
		void highFivesGuys(void);
		
		/* ACCESSORS */

		/* SETTERS */

};

#endif
