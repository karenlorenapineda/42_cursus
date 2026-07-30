/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:30:17 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 18:15:37 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	virtual ~WrongCat();

	WrongCat&	operator=(const WrongCat &cpy);

    void makeSound() const;
};

#endif