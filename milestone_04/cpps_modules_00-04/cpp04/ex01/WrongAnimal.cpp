/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:30:12 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 18:10:56 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy)
{
	std::cout << "WrongAnimal assigment operator called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}
std::string WrongAnimal::getType() const
{
	return this->type;
}