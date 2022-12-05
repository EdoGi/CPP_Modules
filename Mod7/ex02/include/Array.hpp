/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:04:10 by giaco             #+#    #+#             */
/*   Updated: 2022/12/05 19:37:04 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

template<typename T>
class Array
{

	public:

		Array();
		Array( Array<T> const & src );
		~Array();

		Array(unsigned int n);
		
		unsigned int	size() const;
		T &				getElement(unsigned int index) const;
		
		Array<T> &		operator=( Array<T> const & rhs );
		T &			operator[](unsigned int index);

	private:

		T *				_elements;
		unsigned int 	_size;

		class	WrongIndexException : public std::exception
		{
			virtual char const *	what() const throw();
		};
};

template <typename T>
std::ostream &			operator<<( std::ostream & o, Array<T> const & i )
{
	o << "Array is size " << i.size() << '\n';
	for (unsigned int j = 0; j < i.size(); j++)
	{
		o << "[" << j << "] : " << i.getElement(j) << '\n';
	}
	o << std::endl;
	return o;
}

template <typename T>
Array<T>::Array()
{
	std::cout << BGRN << "Default Constructor Called" << RESET << '\n';
	this->_elements = new T();
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << BGRN << "Parametric Constructor Called" << RESET << '\n';
	_elements = new T[n];
}

template <typename T>
Array<T>::Array(Array const & src)
{
	std::cout << BGRN << "Copy Constructor Called" << RESET << '\n';
	this->_elements = new T[src._size];
	this->_size = src._size;
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = src._elements[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	std::cout << RED << "Destructor Called" << RESET << '\n';
	if (this->_size > 0)
		delete [] this->_elements;
}

template <typename T>
Array<T> &		Array<T>::operator=(Array<T> const & rhs)
{
	std::cout << BPUR << "Assign Overload Called" << RESET << '\n';
	if (this != &rhs)
	{
		if (this->_elements)
			delete [] this->_elements;
		this->_elements = new T[rhs.size()];
		this->_size = rhs.size();
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_elements[i] = rhs._elements[i];
		}
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
T & Array<T>::getElement(unsigned int index) const
{
	return (this->_elements[index]);
}

template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw Array::WrongIndexException();
	else
		return _elements[index];
}

template <typename T>
const char * Array<T>::WrongIndexException::what() const throw()
{
	return("Trying to reach invalid Array_Index");
}

#endif /* *********************************************************** ARRAY_H */
