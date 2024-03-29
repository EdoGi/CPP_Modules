/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:49:34 by egiacomi          #+#    #+#             */
/*   Updated: 2023/04/05 01:11:16 by giaco            ###   ########.fr       */
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
