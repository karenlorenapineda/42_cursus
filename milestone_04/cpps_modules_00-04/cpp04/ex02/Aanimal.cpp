/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:39:05 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 20:39:10 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"

Aanimal::Aanimal() : type("Aanimal")
{
	std::cout << "Aanimal default constructor called" << std::endl;
}

Aanimal::Aanimal(const Aanimal &src)
{
	std::cout << "Aanimal copy constructor called" << std::endl;
	*this = src;
}

Aanimal::~Aanimal()
{
	std::cout << "Aanimal destructor called" << std::endl;
}

Aanimal &Aanimal::operator=(const Aanimal &cpy)
{
	std::cout << "Aanimal assigment operator called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return *this;
}

void Aanimal::makeSound() const
{
	std::cout << "Aanimal makes a default sound" << std::endl;
}
std::string Aanimal::getType() const
{
	return this->type;
}