/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:51:03 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/18 19:52:59 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

# define BRAIN_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include "Animal.hpp"

class Brain
{
    std::string ideas[100];

public:
	Brain();
	Brain(const Brain &src);
	virtual ~Brain();

	Brain&	operator=(const Brain &cpy);
};

#endif