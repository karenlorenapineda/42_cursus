/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:04:46 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/16 22:47:04 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default Constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Constructor called with name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
    : ClapTrap(src)
{
    *this = src;
    std::cout << "ScavTrap Copy Constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &cpy)
{
    if (this != &cpy)
    {
        ClapTrap::operator=(cpy);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " tries to attack " << target
            << " but fails!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << name << " attacks " << target
            << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}