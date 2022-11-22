/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:49:21 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/22 02:01:53 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::~Point() {}

Point & Point::operator=(Point const & rhs) {
	(void)rhs;
	return (*this);
}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return(_y);
}
