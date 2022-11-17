/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:49:57 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/17 03:13:12 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANA_
#define _HUMANA_

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
	
	public :
		
		HumanA(std::string nm, Weapon &wp);
		~HumanA(void);

		void attack(void);
		void setWeapon(Weapon new_weapon);
		
	private :

		std::string _name;
		Weapon		&_weapon;
};

#endif
