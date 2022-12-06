/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:37:59 by giaco             #+#    #+#             */
/*   Updated: 2022/12/06 01:53:06 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include "colors.hpp"
# include <cstdlib>
# include <iostream>

template< typename T>
void	iter(T * tab, size_t const & size, void (*fct)(T &))
{
	for (size_t i = 0; i < size; i++)
		fct(tab[i]);
}

template<typename T>
void	display(T &value)
{
	std::cout << "[" << value << "]" << std::endl;
}

template<typename T>
void	increment(T &value)
{
	value++;
}

template<typename T>
void	toupper(T &value)
{
	if (value >= 97 && value <= 122)
		value -= 32;
}

#endif