/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:49:57 by egiacomi          #+#    #+#             */
/*   Updated: 2023/04/05 01:11:03 by giaco            ###   ########.fr       */
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
