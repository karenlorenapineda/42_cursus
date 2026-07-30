/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:23:29 by kpineda-          #+#    #+#             */
/*   Updated: 2026/01/18 20:42:46 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
    int fixed_point;
    static const int fractional_bits = 8;
    
public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &cpy);
    ~Fixed();
    
    float toFloat( void ) const;
    int toInt( void )const;
    int getRawBits( void ) const;
    void setRawBits(int const raw);
    Fixed &operator=(const Fixed &cpy);
    
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);