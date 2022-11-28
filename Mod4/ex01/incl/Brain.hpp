/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:26:55 by giaco             #+#    #+#             */
/*   Updated: 2022/11/28 23:46:11 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );

		std::string	const	*getIdeas() const;
		void				setIdea(size_t index, std::string arg);

		private :
			std::string _ideas[100];

};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */
