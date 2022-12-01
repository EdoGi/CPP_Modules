/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:41:32 by giaco             #+#    #+#             */
/*   Updated: 2022/12/01 02:24:35 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form(std::string name, int gtosign, int gtoexec);
		~Form();

		Form &		operator=( Form const & rhs );

		std::string	getName() const;
		bool		getSigned() const;
		int			getGtoSign() const;
		int			getGtoExec() const;
	
		void		beSigned(Bureaucrat const &SignedBy);
		
	private:

		std::string const	_name;
		bool				_issigned;
		int					_gtosign;
		int					_gtoexec;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */