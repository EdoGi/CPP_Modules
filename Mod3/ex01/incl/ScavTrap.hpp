/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:55:54 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/24 04:18:50 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP
# define SCAV_TRAP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private :

	public :
		
		/* DEFAULT & COPY CONSTRUCTORS + DESTRUCTOR */
		ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		
		/* PARAMETRIC CONSTRUCTOR */
		ScavTrap(std::string const name);
		
		/* ASSIGNEMENT OPERATOR OVERLOAD */
		ScavTrap & operator=(ScavTrap const & rhs);

		void attack(const std::string& target);
		void guardGate(void);
		
		/* ACCESSORS */

		/* SETTERS */

};

#endif
