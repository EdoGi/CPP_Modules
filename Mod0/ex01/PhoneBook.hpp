/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:08:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/11/13 00:13:02 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_H__
#define _PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(void);
	void	search(void);
	void	display(void);

private :

	int		nb;
	Contact contact[8];

};

#endif /* _PHONEBOOK_H__ */