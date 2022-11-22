/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 04:04:23 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/22 04:18:44 by egiacomi         ###   ########.fr       */
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
		
		ClapTrap(void);
		ClapTrap(ClapTrap const & src);
		ClapTrap & operator=(ClapTrap const & rhs);
		~ClapTrap(void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	getName();
		int	getHit();
		int	getEnergy();
		int	getAttack();		
};

#endif