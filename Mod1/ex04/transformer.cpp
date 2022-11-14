/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:20:37 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/14 00:31:27 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformer.hpp"

std::string	transform(std::string s1, std::string s2, std::string buf)
{
	size_t			index = 0;

	index = buf.find(s1, index);
	while (index != std::string::npos)
	{
		buf.erase(index, s1.length());
		buf.insert(index, s2);
		index = index + s1.length();
		index = buf.find(s1, index);
	}
	return (buf);
}