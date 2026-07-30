/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:20 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/16 21:40:42 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	
};

Contact::~Contact()
{
	
};

std::string	Contact::ShellSize(std::string info)
{
	
	if (info.length() > 10)
		return info.substr(0, 9) + ".";
	else
		return std::string(10 - info.length(), ' ') + info;
}


std::string Contact::newContactInfoGetline(std::string info)
{
	std::string command;
	
	while (true)
	{
		std::cout << "Enter " << info << ": ";
		std::getline(std::cin, command);
		if (command.empty())
			continue;
		else
			return command;
	}
}

void Contact::newContactInfo()
{
	contactInfo.firstName = newContactInfoGetline("First Name");
	contactInfo.lastName = newContactInfoGetline("Last Name");
	contactInfo.nickname = newContactInfoGetline("Nickname");
	contactInfo.phoneNumber = newContactInfoGetline("Phone Number");
	contactInfo.darkestSecret = newContactInfoGetline("Darkest Secret");
}

void Contact::VisualiceInfo()
{
	std::cout << "First Name: " << contactInfo.firstName << std::endl
		<< "Last Name: " << contactInfo.lastName << std::endl
		<< "Nickname: " << contactInfo.nickname << std::endl
		<< "Phone Number: " << contactInfo.phoneNumber << std::endl
		<< "Darkest Secret: " << contactInfo.darkestSecret << std::endl;
		
};

void Contact::printContactinfo()
{
	std::cout << ShellSize(contactInfo.firstName) << "|";
	std::cout << ShellSize(contactInfo.lastName) << "|";
	std::cout << ShellSize(contactInfo.nickname) << "|";
	std::cout << std::endl;
		
};