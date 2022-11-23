/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 04:04:23 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/23 08:45:39 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_
# define _CLAPTRAP_

#include <iostream>
#include <string>

class ClapTrap {

	private :
		
		std::string _name;
		int			_hit;
		int			_energy;
		int			_attack;

	public :
		
		/* DEFAULT & COPY CONSTRUCTORS + DESTRUCTOR */
		ClapTrap(void);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		
		/* PARAMETRIC CONSTRUCTOR */
		ClapTrap(std::string const name);
		
		/* ASSIGNEMENT OPERATOR OVERLOAD */
		ClapTrap & operator=(ClapTrap const & rhs);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		/* ACCESSORS */
		std::string	getName() const;
		int	getHit() const;
		int	getEnergy() const;
		int	getAttack() const;

		/* SETTERS */
		void	setAttack(int new_attack);	
};

#endif
