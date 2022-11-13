/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:49:34 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 04:23:49 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_
#define _WEAPON_

#include <iostream>
#include <string>

class Weapon {
	
	public :
		
		Weapon(std::string name);
		~Weapon(void);

		std::string const & getType(); 
		void setType(std::string god_craft);
		
	private :

		std::string _type;
};

#endif