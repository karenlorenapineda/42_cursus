/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:39:47 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 19:45:37 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	Brain *brain;
public:
	Cat();
	Cat(const Cat &src);
	virtual ~Cat();

	Cat&	operator=(const Cat &cpy);

    virtual void makeSound() const;
};

#endif