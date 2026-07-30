/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:25 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/16 21:30:51 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	Contact contacts[8];
	int		contactAmount;
	int		contactCount;
	
	void	printTable();
	
public:
	PhoneBook();
	~PhoneBook();
	void Add();
	void Search();
};

#endif