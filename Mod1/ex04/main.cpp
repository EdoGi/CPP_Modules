/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:14:45 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/14 00:39:26 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformer.hpp"

std::string buf_create(std::ifstream *ifs)
{
	std::stringstream	buffer;
	buffer << ifs->rdbuf();
	return (buffer.str());
}

bool init_strs(std::string *s1, std::string *s2, std::string *filename, char** av)
{
	*filename = av[1];
	*s1 = av[2];
	if (s1->empty())
		return 1;
	*s2 = av[3];
	return 0;
}

bool init_iostream(char **av, std::ifstream *ifs, std::ofstream *ofs, std::string filename)
{
	ifs->open(av[1], std::ifstream::in);
	if (!ifs || ifs->is_open() == false || ifs->fail() == true)
	{
		std::cout << "Error with input file" << std::endl;
		return 1;
	}
	ofs->open(filename.c_str(), std::ofstream::out);
	if (!ofs)
	{
		std::cout << "Error with output file" << std::endl;
		ifs->close();
		return 1;
	}
	return 0;
}

int main(int ac, char **av)
{
	std::string			filename;
	std::string 		s1;
	std::string 		s2;
	
	std::ifstream 		ifs;
	std::ofstream 		ofs;
	std::string 		buf;
	
	if (ac == 4)
	{
		if (init_strs(&s1, &s2, &filename, av))
		{
			std::cout << "You must type a word to change.." << std::endl;
			return 2;
		}
		filename.append(".replace");
		if (init_iostream(av, &ifs, &ofs, filename))
			return 1;
		buf = buf_create(&ifs);
		ofs << transform(s1, s2, buf);
		ifs.close();
		ofs.close();
	}
	else
	{
		std::cout << "Wrong number of arguments.. you must enter : \n> ./transformer <filename> <word_to_replace> <new_word>." << std::endl;
		return 2;
	}
	return 0;
}