/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:33:44 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 02:51:02 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
# include "colors.hpp"

typedef struct 	s_Data
{
	int				value;
	const char *	word;
}				Data;

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif
