/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:30:09 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 18:08:17 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include <unistd.h>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &cpy);

	void makeSound() const;
	std::string getType() const;
};

#endif