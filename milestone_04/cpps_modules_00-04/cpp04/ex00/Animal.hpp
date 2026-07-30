/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:33:36 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 18:05:24 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <unistd.h>

class Animal
{
protected:
    std::string type;

public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();

	Animal&	operator=(const Animal &cpy);

    virtual void makeSound() const;
	std::string getType() const;
};

#endif