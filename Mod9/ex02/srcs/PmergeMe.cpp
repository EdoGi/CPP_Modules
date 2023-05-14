/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:07:35 by giaco             #+#    #+#             */
/*   Updated: 2023/05/14 20:07:57 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
	*this = src;
}

PmergeMe::PmergeMe(std::string num_list)
{
	std::istringstream iss(num_list);
	std::string token;
	while (iss >> token)
	{
   		for(size_t i = 0; i < token.length(); i++)
      	{
			if(!isdigit(token[i]))
				throw std::runtime_error(std::string("Error : list contain non numeric character"));
		}
		this->John_vector.push_back(atoi(token.c_str()));
		this->Lana_deque.push_back(atoi(token.c_str()));
	}
	this->unsorted = John_vector;
}

PmergeMe &	PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->John_vector = rhs.GetJohnVector();
		this->Lana_deque = rhs.GetLanaDeque();
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

std::deque<int> PmergeMe::GetLanaDeque() const
{
	return (this->Lana_deque);
}

std::vector<int> PmergeMe::GetUnsorted() const
{
	return (this->unsorted);
}

std::ostream & operator<<(std::ostream& os, const PmergeMe & link)
{
    std::vector<int> unsorted = link.GetUnsorted();
    std::vector<int> sorted = link.GetJohnVector();
	
	os << "Before : ";
	for (size_t i = 0; i < unsorted.size(); i++)
		os << unsorted[i] << ' ';
	os << "\nAfter : ";
	for (size_t i = 0; i < sorted.size(); i++)
		os << sorted[i] << ' ';
	os << "\nTime to process a range of " << unsorted.size() << " elements with std::vector : " << link.GetTime('v') + link.GetTime('m') << "us";
	os << "\nTime to process a range of " << unsorted.size() << " elements with std::deque : " << link.GetTime('d') + link.GetTime('m') << "us";
    return os;
}

void PmergeMe::MerSertSort()
{
	timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	VecSort(this->John_vector);
	gettimeofday(&end_time, NULL);
	SetTime('v', start_time, end_time);
	gettimeofday(&start_time, NULL);
	DeqSort(this->Lana_deque);
	gettimeofday(&end_time, NULL);
	SetTime('d', start_time, end_time);	
}

float PmergeMe::GetTime(char t) const
{
	if (t == 'm' || t == 'M')
		return(this->DataMgt_time);
	else if (t == 'v' || t == 'V')
		return(this->VecSort_time);
	else if (t == 'd' || t == 'D')
		return(this->DeqSort_time);
	else
		throw std::runtime_error(std::string("Error : wrong SetTime"));
}

void PmergeMe::SetTime(char t, timeval start_time, timeval end_time)
{
	float v = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
	if (t == 'm' || t == 'M')
		this->DataMgt_time = v;
	else if (t == 'v' || t == 'V')
		this->VecSort_time = v;
	else if (t == 'd' || t == 'D')
		this->DeqSort_time = v;
	else
		throw std::runtime_error(std::string("Error : wrong GetTime"));
}