/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:00:47 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 19:24:35 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define WEAPON_HPP

#include <iostream>
#include <string>
#include <sstream>

class Weapon
{
	std::string type;

public:
	Weapon(std::string name);
	~Weapon();
	
	const std::string getType();
	void setType(std::string newType);
};

#endif