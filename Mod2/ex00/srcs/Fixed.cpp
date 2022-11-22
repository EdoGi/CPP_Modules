/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:04:03 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/21 23:19:02 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Nombre de bit fractionnaire ; Static definition */
int const Fixed::_nBits = 8;

/* Constructeur par default */
Fixed::Fixed(void) : _RawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

/* Constructeur par copie */
Fixed::Fixed(Fixed const & copy) {
	std::cout << "Copy constructor called" << std::endl;
	// this->_RawBits = copy.getRawBits();
	*this = copy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/* Operateur d'assignation */
Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;	
	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_RawBits);
}
	
void Fixed::setRawBits(int const raw) {
	this->_RawBits = raw;
}
