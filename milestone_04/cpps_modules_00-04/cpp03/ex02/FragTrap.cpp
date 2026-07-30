/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:29:05 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/16 22:46:55 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("FragTrap")
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default Constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Constructor called with name: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
    : ClapTrap(src)
{
    *this = src;
    std::cout << "FragTrap Copy Constructor called!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " Destructor called " << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &cpy)
{
    if (this != &cpy)
    {
        ClapTrap::operator=(cpy);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints <= 0)
    {
        std::cout << "FragTrap " << name << " tries to attack " << target
            << " but fails!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << name << " attacks " << target
            << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " is giving a high five!" << std::endl;
}