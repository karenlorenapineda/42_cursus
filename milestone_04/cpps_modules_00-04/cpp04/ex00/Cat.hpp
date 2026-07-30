/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:39:47 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 18:05:40 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &src);
	virtual ~Cat();

	Cat&	operator=(const Cat &cpy);

    virtual void makeSound() const;
};

#endif