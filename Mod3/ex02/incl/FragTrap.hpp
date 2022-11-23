/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:57:08 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/23 09:03:14 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

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
		void beRepaired(unsigned int amount);
		
		/* ACCESSORS */

		/* SETTERS */

};

#endif
