/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:23 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/16 21:38:51 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>
# include <sstream>

struct	Info
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

class Contact
{
	Info contactInfo;
	
	std::string	ShellSize(std::string info);
	std::string newContactInfoGetline(std::string info);
public:
	Contact();
	~Contact();
	void VisualiceInfo();
	void printContactinfo();
	void newContactInfo();
};

#endif