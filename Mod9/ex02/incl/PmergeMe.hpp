/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:07:37 by giaco             #+#    #+#             */
/*   Updated: 2023/05/15 17:04:20 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <sys/time.h>
# include <iomanip>
# include <limits.h>

# define SUCCESS 0
# define FAILURE 1
# define K 5

class PmergeMe
{
	private:
		
		std::vector<int> _John_vector;
		std::deque<int> _Lana_deque;
		std::vector<int> _unsorted;
		double			_DataMgt_time;
		double			_VecSort_time;
		double			_DeqSort_time;
		
	public:
	
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe(char **av);
		~PmergeMe();

		PmergeMe & operator=( PmergeMe const & rhs );

		void MerSertSort();

		void			SetTime(char t, timeval start_time, timeval end_time);
		float			GetTime(char t) const;
		std::vector<int> GetJohnVector() const;
		std::deque<int> GetLanaDeque() const;
		std::vector<int> GetUnsorted() const;
		bool isSorted() const;
};

std::ostream & operator<<(std::ostream & os, PmergeMe const & link);

void VecSort(std::vector<int> & JohnII);
void DeqSort(std::deque<int> & LanaII);

#endif