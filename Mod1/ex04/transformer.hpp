/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:20:27 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/14 00:37:07 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRANSFORMER_
#define _TRANSFORMER_

#include <iostream>
#include <fstream>
#include <sstream>

std::string	transform(std::string s1, std::string s2, std::string buf);
std::string buf_create(std::ifstream *ifs);
bool 		init_strs(std::string *s1, std::string *s2, std::string *filename, char** av);
bool 		init_iostream(char **av, std::ifstream *ifs, std::ofstream *ofs, std::string filename);
int 		main(int ac, char **av);
	
#endif