/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:32:56 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/14 02:36:02 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_
#define _HARL_

#include <string>
#include <iostream>

# define RESET "\e[0m"
# define BWHT "\e[1;37m"
# define UYEL "\e[4;33m"

class Harl {
	
	public :

		void complain(std::string level);

	private :
	
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
				
};

#endif