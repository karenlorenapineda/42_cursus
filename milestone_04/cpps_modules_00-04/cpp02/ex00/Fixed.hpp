/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:23:29 by kpineda-          #+#    #+#             */
/*   Updated: 2026/01/13 20:28:34 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
    int fixed_point;
    static const int fractional_bits = 8;
    
public:
    Fixed();
    Fixed(const Fixed &cpy);
    ~Fixed();
    
    int getRawBits( void ) const;
    void setRawBits(int const raw);
    Fixed &operator=(const Fixed &cpy);
    
};