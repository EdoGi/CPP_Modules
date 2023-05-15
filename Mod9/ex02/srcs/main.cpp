/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:07:29 by giaco             #+#    #+#             */
/*   Updated: 2023/05/15 00:12:47 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void NumPrint(std::vector<int> *VtP, std::deque<int> *DtP, std::string message)
{
	std::cout << message;
	if (VtP)
	{
		for (size_t i = 0; i < VtP->size(); i++)
			std::cout << VtP->at(i) << ' ';
	}
	else if (DtP)
	{
		for (size_t i = 0; i < DtP->size(); i++)
			std::cout << DtP->at(i) << ' ';
	}
	else
		std::cout << "N/A";
	std::cout << std::endl;	
}

void VecInsert(std::vector<int> & JohnJr)
{
    size_t n = JohnJr.size();
	for (size_t key = 1; key < n; key++)
	{
		size_t j = key;
		while (j > 0 && JohnJr[j - 1] > JohnJr[j])
		{
			std::swap(JohnJr[j], JohnJr[j - 1]);
				j--;
		}
	}
}

void VecMerge(std::vector<int> & JohnJr, std::vector<int> & JohnJr1, std::vector<int> & JohnJr2)
{	
	for (size_t i = 0; i < JohnJr.size(); i++)
	{
		if (JohnJr1.empty())
		{
			JohnJr.erase(JohnJr.begin() + i, JohnJr.end());
			JohnJr.insert(JohnJr.end(), JohnJr2.begin(), JohnJr2.end());
			break;
		}
		else if (JohnJr2.empty())
		{
			JohnJr.erase(JohnJr.begin() + i, JohnJr.end());
			JohnJr.insert(JohnJr.end(), JohnJr1.begin(), JohnJr1.end());
			break;
		}
		else if (JohnJr1.front() < JohnJr2.at(0))
		{
			JohnJr[i] = JohnJr1[0];
			JohnJr1.erase(JohnJr1.begin());
		}
		else
		{
			JohnJr[i] = JohnJr2[0];	
			JohnJr2.erase(JohnJr2.begin());
		}
	}
}

void VecSort(std::vector<int> & JohnJr)
{
	if (JohnJr.size() > K)
	{
		std::vector<int> JohnJr1(JohnJr.begin(), JohnJr.begin() + JohnJr.size()/2);
		std::vector<int> JohnJr2(JohnJr.begin() + JohnJr.size()/2, JohnJr.end());
		VecSort(JohnJr1);
		VecSort(JohnJr2);
		VecMerge(JohnJr, JohnJr1, JohnJr2);
	}
	else
		VecInsert(JohnJr);
}

void DeqInsert(std::deque<int> & LanaJr)
{
    size_t n = LanaJr.size();
	for (size_t key = 1; key < n; key++)
	{
		size_t j = key;
		while (j > 0 && LanaJr[j - 1] > LanaJr[j])
		{
			std::swap(LanaJr[j], LanaJr[j - 1]);
				j--;
		}
	}
}

void DeqMerge(std::deque<int> & LanaJr, std::deque<int> & LanaJr1, std::deque<int> & LanaJr2)
{	
	for (size_t i = 0; i < LanaJr.size(); i++)
	{
		if (LanaJr1.empty())
		{
			LanaJr.erase(LanaJr.begin() + i, LanaJr.end());
			LanaJr.insert(LanaJr.end(), LanaJr2.begin(), LanaJr2.end());
			break;
		}
		else if (LanaJr2.empty())
		{
			LanaJr.erase(LanaJr.begin() + i, LanaJr.end());
			LanaJr.insert(LanaJr.end(), LanaJr1.begin(), LanaJr1.end());
			break;
		}
		else if (LanaJr1.at(0) < LanaJr2.at(0))
		{
			LanaJr[i] = LanaJr1[0];
			LanaJr1.pop_front();
		}
		else
		{
			LanaJr[i] = LanaJr2[0];	
			LanaJr2.pop_front();
		}
	}
}

void DeqSort(std::deque<int> & LanaJr)
{
	if (LanaJr.size() > K)
	{
		std::deque<int> LanaJr1(LanaJr.begin(), LanaJr.begin() + LanaJr.size()/2);
		std::deque<int> LanaJr2(LanaJr.begin() + LanaJr.size()/2, LanaJr.end());
		DeqSort(LanaJr1);
		DeqSort(LanaJr2);
		DeqMerge(LanaJr, LanaJr1, LanaJr2);
	}
	else
		DeqInsert(LanaJr);
}

int	main(int ac, char **av)
{
    timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
	if (ac < 3)
	{
		std::cerr << "Error : correct usage is ./PmergeMe <string : list of numbers to sort>" << std::endl;
		return FAILURE;
	}
	
	try
	{
		PmergeMe Jona(av);
  		gettimeofday(&end_time, NULL);
		Jona.SetTime('m', start_time, end_time);
		Jona.MerSertSort();
		std::cout << Jona << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return  FAILURE;
	}
	
	return SUCCESS;

}