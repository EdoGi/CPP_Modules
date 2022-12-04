/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Caster.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:46:38 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 02:26:13 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTER_HPP
# define CASTER_HPP

# include <iostream>
# include <climits>
# include <cmath>
# include <iomanip>
# include "colors.hpp"

typedef enum	t_type
{
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
}				t_type;

class Caster
{

	public:

		Caster();
		Caster( Caster const & src );
		Caster(const char *value);
		~Caster();

		Caster &		operator=( Caster const & rhs );
		
		bool	isChar(const char *value);
		bool	isInt(const char *value);
		bool	isFloat(const char *value);
		bool	isDouble(const char *value);

		void	init_caster();
		void	casting();
		void	castingcheck();
		
		void	displayer(Caster &ref) const;

	private:

		const char *_value;
		t_type		_type;
		
		char		_char;
		int			_int;
		float		_float;
		double		_double;
		
		bool		_isprint;
		bool		_validChar;
		bool		_validInt;
};

#endif /* ********************************************************** CASTER_H */