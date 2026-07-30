/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:36:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/19 18:32:51 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP

# define AANIMAL_HPP

# include <iostream>
# include <string>
# include <unistd.h>

class Aanimal
{
protected:
    std::string type;

public:
	Aanimal();
	Aanimal(const Aanimal &src);
	virtual ~Aanimal();

	Aanimal&	operator=(const Aanimal &cpy);

    virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif