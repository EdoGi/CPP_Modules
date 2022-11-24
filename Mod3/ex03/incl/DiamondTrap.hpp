/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:44:05 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/24 04:43:26 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

#include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	private :
		
		std::string _name;
		
	public :
		
		/* DEFAULT & COPY CONSTRUCTORS + DESTRUCTOR */
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);
		
		/* PARAMETRIC CONSTRUCTOR */
		DiamondTrap(std::string const name);
		
		/* ASSIGNEMENT OPERATOR OVERLOAD */
		DiamondTrap & operator=(DiamondTrap const & rhs);

		using	ScavTrap::attack;
		void	whoAmI(void);
		
		/* ACCESSORS */

		/* SETTERS */

};

#endif
