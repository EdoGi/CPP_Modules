/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:07:35 by giaco             #+#    #+#             */
/*   Updated: 2023/04/21 16:43:22 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
	*this = src;
}

PmergeMe &	PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->John_vector = rhs.GetJohnVector();
		this->Kristy_list = rhs.GetKristyList();
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

std::vector<int> PmergeMe::GetJohnVector() const
{
	return (this->John_vector);
}

std::list<int> PmergeMe::GetKristyList() const
{
	return (this->Kristy_list);
}