/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:38:25 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 18:05:54 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &src);
	virtual ~Dog();

	Dog&	operator=(const Dog &cpy);

    virtual void makeSound() const;
};

#endif