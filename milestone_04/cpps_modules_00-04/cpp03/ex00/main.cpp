/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:55:58 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/16 22:46:33 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap1("clapTrap1");
	ClapTrap clapTrap2("clapTrap2");

	clapTrap1.attack("clapTrap2");
	clapTrap2.takeDamage(10);
	clapTrap1.beRepaired(2);
	clapTrap1.beRepaired(123);

	return 0;
}