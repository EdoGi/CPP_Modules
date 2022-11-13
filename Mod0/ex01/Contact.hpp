/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:13:27 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/12 18:31:42 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>

class Contact {

public:

	Contact( void );
	~Contact( void );

	std::string	get_First(void) const;
	void		set_First(std::string);
	std::string	get_Last(void) const;
	void		set_Last(std::string);
	std::string	get_Nick(void) const;
	void		set_Nick(std::string);
	std::string	get_Phone(void) const;
	void		set_Phone(std::string);
	std::string	get_Secret(void) const;
	void		set_Secret(std::string);

	void		clear_contact(void);
	void		fill_infos(int cnum);
	void		display_contact(void);
	void		display_detail(void);
	
private:

	int			_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_num;
	std::string	_secret;
};

#endif /* _CONTACT_H_ */