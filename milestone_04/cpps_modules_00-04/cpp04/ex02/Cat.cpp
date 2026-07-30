/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:23:41 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 19:59:00 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	brain = new Brain(*src.brain);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cpy)
{
	std::cout << "Cat assigment operator called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
		this->brain = cpy.brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
