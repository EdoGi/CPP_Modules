/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:07:37 by giaco             #+#    #+#             */
/*   Updated: 2023/04/21 16:43:02 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP
# include <vector>
# include <list>

class PmergeMe
{
	private:
		
		std::vector<int> John_vector;
		std::list<int> Kristy_list;
		
	public:
	
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		~PmergeMe();

		PmergeMe & operator=( PmergeMe const & rhs );

		std::vector<int> GetJohnVector() const;
		std::list<int> GetKristyList() const;	

};

#endif