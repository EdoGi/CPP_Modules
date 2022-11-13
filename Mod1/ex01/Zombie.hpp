/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:06:15 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 03:16:14 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_
#define _ZOMBIE_

#include <string>
#include <iostream>

class Zombie {
	
	public :
		
		Zombie(void);
		~Zombie(void);
		
		void announce(void);
		void setName(std::string name);
		
	private :

		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);
	
#endif