/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:41:32 by giaco             #+#    #+#             */
/*   Updated: 2022/12/02 10:27:15 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form(std::string const name, int const gtosign, int const gtoexec);
		~Form();

		Form &		operator=( Form const & rhs );

		std::string	getName() const;
		bool		getSigned() const;
		int			getGtoSign() const;
		int			getGtoExec() const;
	
		void		beSigned(Bureaucrat const &SignedBy);

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};		
		
	private:

		std::string const	_name;
		bool				_issigned;
		int const			_gtosign;
		int const			_gtoexec;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */