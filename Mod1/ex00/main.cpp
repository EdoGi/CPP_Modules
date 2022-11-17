/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:06:09 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/17 03:06:55 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	/* Create a Zombie directly in the main and show that the name is well set*/
	Zombie Carl = Zombie("Carl Stack");
	Carl.announce();
	
	/* Function newZombie and annouce to show that the Zombie can be used outside its scope */
	Zombie *Greg = newZombie("Greg Heap");
	Greg->announce();
	
	/* Function that creates a Zombie and kill it when function ends */
	randomChump("Donald Chump");
	
	delete Greg;
	
	return 0;
}
