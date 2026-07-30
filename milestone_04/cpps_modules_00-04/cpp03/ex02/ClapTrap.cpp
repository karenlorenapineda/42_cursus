/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:55:54 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/16 22:46:52 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoints(10),
 energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called " << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(2), attackDamage(0)
{
	std::cout << "ClapTrap Constructor called with name: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
	std::cout << "ClapTrap Copy Constructor called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " Destructor called " << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & cpy)
{
	if (this != &cpy) {
		this->name = cpy.name;
		this->hitPoints = cpy.hitPoints;
		this->energyPoints = cpy.energyPoints;
		this->attackDamage = cpy.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{

	if(energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " tries to attack " << target
			<< " but fail!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target
			<< " causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints --;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else hitPoints -= amount;
		std::cout << name << " takes "<< amount  << " points of damage!" << std::endl;
    if (hitPoints <= 0) 
	    std::cout << name << " dies under terrible circunstances..." << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{	
	if(energyPoints <= 0)
		std::cout << name << " tries to heal " << " but fail!" << std::endl;
	else
	{
		hitPoints += amount;
			std::cout << name << " heals " << amount << "! " << std::endl;
		energyPoints --;
	}
}