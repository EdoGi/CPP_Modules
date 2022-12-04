/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:57:51 by egiacomi          #+#    #+#             */
/*   Updated: 2022/12/04 03:01:53 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t retvalue;
	retvalue = reinterpret_cast<uintptr_t>(ptr);
	return (retvalue);
}

Data* deserialize(uintptr_t raw)
{
	Data *retvalue;
	retvalue = reinterpret_cast<Data*>(raw);
	return (retvalue);	
}