/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:33:44 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 04:27:47 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <exception>

class Base
{

	public:
		
		virtual ~Base();

	private:

};

void identify(Base* p);
void identify(Base& p);

#endif /* ************************************************************ BASE_H */
