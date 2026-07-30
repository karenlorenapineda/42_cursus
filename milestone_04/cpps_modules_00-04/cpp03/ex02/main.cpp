/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:55:58 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/16 22:46:59 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap FragTrap1("First");
	FragTrap FragTrap2("Second");

	FragTrap1.attack("Second");
	FragTrap2.takeDamage(30);
	FragTrap2.attack("First");
	FragTrap1.takeDamage(30);

	FragTrap1.beRepaired(30);
	FragTrap2.beRepaired(30);

	FragTrap1.highFivesGuys();
	FragTrap2.highFivesGuys();

	return 0;
}