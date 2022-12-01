/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giaco <giaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:27:12 by giaco             #+#    #+#             */
/*   Updated: 2022/12/01 01:21:20 by giaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string getName() const;
		int			getGrade() const;
		void				increment();
		void				decrement();


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
		int					_grade;
		
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
