/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:26:44 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 19:58:46 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	brain = new Brain(*src.brain);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &cpy)
{
	std::cout << "Dog assigment operator called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
		this->brain = cpy.brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
