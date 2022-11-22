/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:04:11 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/21 23:21:20 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>
# include <cmath>

class Fixed {

	private :
		int					_RawBits;
		static int const	_nBits;

	public :
		Fixed(void);
		Fixed(Fixed const & copy);
		Fixed(int const intco);
		Fixed(float const floatco);
		~Fixed(void);

		Fixed &	operator=(Fixed const & assign);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const & rhs);

#endif
