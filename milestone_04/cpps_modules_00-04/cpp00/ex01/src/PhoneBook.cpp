/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:18 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/22 20:18:59 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Welcome to your ";
    std::cout << "\033[31mA\033[0m";
    std::cout << "\033[32mW\033[0m";
    std::cout << "\033[33mE\033[0m";
    std::cout << "\033[34mS\033[0m";
    std::cout << "\033[35mO\033[0m";
    std::cout << "\033[36mM\033[0m";
    std::cout << "\033[91mE\033[0m";
    std::cout << " PhoneBook!" << std::endl;
    std::cout << "You can: " << std::endl;
    std::cout << "\033[32mADD\033[0m: add new contact"  << std::endl;
    std::cout << "\033[36mSEARCH\033[0m: search for an existing contact" << std::endl;
    std::cout << "\033[31mEXIT\033[0m: exit the program" << std::endl;

	contactCount = 0;
	contactAmount = 0;
};


void PhoneBook::Add()
{
	if (contactCount >= 8)
		contactCount = 0;
	contacts[contactCount].newContactInfo();
	std::cout << "Contact saved!" << contactCount << std::endl;
	contactCount++;
	if (contactAmount < 8)
		contactAmount++;
};

void	PhoneBook::printTable()
{
	std::cout << "+----------+----------+----------+----------+"<< std::endl;
    std::cout << "|     Index| FirstName|  LastName|  Nickname|"<< std::endl;
    std::cout << "+----------+----------+----------+----------+"<< std::endl;
	for (int i= 0; i < contactAmount; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		contacts[i].printContactinfo();
	}
	for (int i = contactAmount; i < 8; i++)
	{
		std::cout << "|         " << i + 1;
		std::cout << "|          |          |          |"<< std::endl;
    }
    std::cout << "+----------+----------+----------+----------+"<< std::endl;
}

void PhoneBook::Search()
{
	printTable();
	
	std::cout << "Enter a Index Number: ";
	
	std::string line;
	int index;
	getline(std::cin, line);
	
	std::stringstream sline(line);
	if (!(sline >> index))
		std::cout << "Invalid Index" << std::endl;
	else if (index > 0 && index <= contactAmount)
		contacts[index - 1].VisualiceInfo();
	else
		std::cout << "Out of range!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "See u soon :D" << std::endl;
};