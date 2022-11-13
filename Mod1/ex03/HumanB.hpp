/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:50:00 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 04:56:07 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANB_
#define _HUMANB_

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
	
	public :
		
		HumanB(std::string nm);
		~HumanB(void);

		void attack(void);
		void setWeapon(Weapon &new_weapon);
		
	private :

		std::string _name;
		Weapon*		_weapon;
};

#endif
