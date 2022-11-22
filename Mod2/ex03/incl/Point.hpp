/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:42:21 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/22 02:05:01 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_HPP_
# define _POINT_HPP_

# include <iostream>
# include "Fixed.hpp"

class Point {

	private :
		Fixed const _x;
		Fixed const _y;

	public :
		Point(void);
		Point(Point const & copy);
		Point(float const x, float const y);
		~Point(void);

		Point &	operator=(Point const & assign);
		
		Fixed getX() const;
		Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream & operator<<(std::ostream &o, Point const & rhs);

#endif
