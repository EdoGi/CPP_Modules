/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:07:35 by giaco             #+#    #+#             */
/*   Updated: 2023/05/15 00:19:02 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
	*this = src;
}

PmergeMe::PmergeMe(char** av)
{
	for (int i = 1; av[i]; i++)
	{
		std::istringstream iss(av[i]);
		int token;
		iss >> token;
		
		int num = token;
		if (iss.fail())
			throw std::runtime_error("Error : Non numeric element in list");	
		if (num < 0 || num > INT_MAX)
		{
			std::stringstream ss;
			ss << "Error: " << token << " is not a valid positive number";
			throw std::runtime_error(ss.str());
		}
		this->_John_vector.push_back(num);
		this->_Lana_deque.push_back(num);
	}
	this->_unsorted = _John_vector;
	if (this->isSorted())
		throw std::runtime_error("Error : List of number already sorted (or with one element only)");
}

PmergeMe &	PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_John_vector = rhs.GetJohnVector();
		this->_Lana_deque = rhs.GetLanaDeque();
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

std::vector<int> PmergeMe::GetJohnVector() const
{
	return (this->_John_vector);
}

std::deque<int> PmergeMe::GetLanaDeque() const
{
	return (this->_Lana_deque);
}

std::vector<int> PmergeMe::GetUnsorted() const
{
	return (this->_unsorted);
}

std::ostream & operator<<(std::ostream& os, const PmergeMe & link)
{
    std::vector<int> unsorted = link.GetUnsorted();
    std::vector<int> sorted = link.GetJohnVector();
	
	os << "\nBefore : ";
	for (size_t i = 0; i < unsorted.size(); i++)
		os << unsorted[i] << ' ';
	os << "\n\nAfter : ";
	for (size_t i = 0; i < sorted.size(); i++)
		os << sorted[i] << ' ';
	os << "\n\nTime to process a range of " << unsorted.size() << " elements with std::vector : " << link.GetTime('v') + link.GetTime('m') << "us";
	os << "\nTime to process a range of " << unsorted.size() << " elements with std::deque : " << link.GetTime('d') + link.GetTime('m') << "us";
    return os;
}

void PmergeMe::MerSertSort()
{
	timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	VecSort(this->_John_vector);
	gettimeofday(&end_time, NULL);
	SetTime('v', start_time, end_time);
	gettimeofday(&start_time, NULL);
	DeqSort(this->_Lana_deque);
	gettimeofday(&end_time, NULL);
	SetTime('d', start_time, end_time);	
}

float PmergeMe::GetTime(char t) const
{
	if (t == 'm' || t == 'M')
		return(this->_DataMgt_time);
	else if (t == 'v' || t == 'V')
		return(this->_VecSort_time);
	else if (t == 'd' || t == 'D')
		return(this->_DeqSort_time);
	else
		throw std::runtime_error(std::string("Error : wrong SetTime"));
}

void PmergeMe::SetTime(char t, timeval start_time, timeval end_time)
{
	float v = (end_time.tv_sec - start_time.tv_sec) * 1000000LL + (end_time.tv_usec - start_time.tv_usec);
	if (t == 'm' || t == 'M')
		this->_DataMgt_time = v;
	else if (t == 'v' || t == 'V')
		this->_VecSort_time = v;
	else if (t == 'd' || t == 'D')
		this->_DeqSort_time = v;
	else
		throw std::runtime_error(std::string("Error : wrong GetTime"));
}

bool	PmergeMe::isSorted() const
{
	if (_unsorted.size() <= 1)
		return (true);

	for (size_t i = 0; i < _unsorted.size() - 1; i++)
	{
		if (_unsorted[i] > _unsorted[i + 1])
			return (false);
	}
	return (true);
}