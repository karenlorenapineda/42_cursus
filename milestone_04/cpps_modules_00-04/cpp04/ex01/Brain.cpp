/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:51:06 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/19 19:35:06 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << i + 1;
		this->ideas[i] =  "Idea " + ss.str();
		std::cout << this->ideas[i] << std::endl;
	}
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assigment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}
