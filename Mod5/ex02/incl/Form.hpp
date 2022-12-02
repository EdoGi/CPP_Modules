/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:41:32 by giaco             #+#    #+#             */
/*   Updated: 2022/12/02 08:03:57 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form(std::string const ame, int const gtosign, int const gtoexec);
		virtual ~Form();

		Form &		operator=( Form const & rhs );

		std::string	getName() const;
		bool		getSigned() const;
		int			getGtoSign() const;
		int			getGtoExec() const;
	
		void				beSigned(Bureaucrat const &SignedBy);
		void				execute(Bureaucrat const &executor) const;
		virtual void		execute(void) const = 0;

		class UnsignedException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class AlreadySignedException : public std::exception
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