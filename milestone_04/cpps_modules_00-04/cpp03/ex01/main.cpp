/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:55:58 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/16 22:46:41 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap1("First");
	ScavTrap scavTrap2("Second");

	scavTrap1.attack("Second");
	scavTrap2.takeDamage(20);
	scavTrap2.attack("First");
	scavTrap1.takeDamage(20);

	scavTrap1.beRepaired(20);
	scavTrap2.beRepaired(20);

	scavTrap1.guardGate();
	scavTrap2.guardGate();

	return 0;
}