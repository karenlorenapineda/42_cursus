/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:11:26 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 19:24:27 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	type = name;
}

Weapon::~Weapon()
{
	
}

const std::string Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string newType)
{
	std::cout << "Weapon of type: " << type;
	type = newType;
	std::cout << ". Changes to: " << type << std::endl;
}