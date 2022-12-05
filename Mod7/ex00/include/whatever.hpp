/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:00 by giaco             #+#    #+#             */
/*   Updated: 2022/12/05 02:16:24 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
void	swap(T & x, T & y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
T	max(T const & x, T const & y)
{
	return ((x>y) ? x : y);
}

template< typename T >
T	min(T const & x, T const & y)
{
	return ((x<y) ? x : y);
}

#endif