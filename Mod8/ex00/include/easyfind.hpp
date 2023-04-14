/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 03:06:29 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/06 05:30:35 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "colors.hpp"
# include <algorithm>
# include <iostream>

template< typename T>
bool easyfind(T const & container, int elem)
{
	typename T::const_iterator it_start = container.begin();
	typename T::const_iterator it_last = container.end();
	
	
	if (std::find(it_start, it_last, elem) == it_last)
		return (false);
	return (true);
}

#endif