/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:32:56 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/17 02:05:45 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_
# define _HARL_

# include <string>
# include <iostream>

class Harl
{
	private:
	
		void _debug(void) const;
		void _info(void) const;
		void _warning(void) const;
		void _error(void) const;
		
	public:

		Harl(void);
		~Harl();
		void complain(std::string level);
};

#endif