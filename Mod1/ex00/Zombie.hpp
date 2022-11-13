/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:06:15 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 02:05:24 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_
#define _ZOMBIE_

#include <string>
#include <iostream>

class Zombie {
	
	public :
		
		Zombie(std::string name);
		~Zombie(void);
		
		void announce(void);

	private :

		std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
	
#endif