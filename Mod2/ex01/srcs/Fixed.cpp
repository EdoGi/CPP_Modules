/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:04:03 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/21 23:25:12 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_nBits = 8;

Fixed::Fixed(void) : _RawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy) {
	std::cout << "Copy constructor called" << std::endl;
	// this->_RawBits = copy.getRawBits();
	*this = copy;
}

/* 
	Conversion du Int en Virgule fixe ; On decalle la virgule de _nBits sur la gauche
*/
Fixed::Fixed(int const intco) {
	std::cout << "Int constructor called" << std::endl;
	this->_RawBits = intco << _nBits;
}

/* 
	Conversion du Float en Virgule fixe ; On decalle la virgule de _nBits sur la gauche
*/
Fixed::Fixed(float const floatco) {
	std::cout << "Float constructor called" << std::endl;
	this->_RawBits = roundf(floatco * (1 << _nBits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;	
	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_RawBits);
}
	
void Fixed::setRawBits(int const raw) {
	this->_RawBits = raw;
}

/* 
	Conversion Float de Virgule fixe en Virgule flottante; On decalle la virgule de _nBits sur la droite
*/
float Fixed::toFloat(void) const {
	return ((float)this->_RawBits / (float)(1 << _nBits));
}

/* 
	Conversion Int de Virgule fixe en Virgule flottante; On decalle la virgule de _nBits sur la droite
*/
int Fixed::toInt(void) const {
	return (this->_RawBits >> _nBits);
}

/* 	
	Surcharge de l’opérateur d’insertion («) : 
	insère une représentation en virgule flottante 
	du nombre à virgule fixe dans le flux de sortie 
*/
std::ostream & operator<<(std::ostream &o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}
