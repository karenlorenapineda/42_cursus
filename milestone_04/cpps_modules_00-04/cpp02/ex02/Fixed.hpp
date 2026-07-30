/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:23:29 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/03 19:18:43 by kpineda-         ###   ########.fr       */
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
    
    // comparision
    bool operator==(const Fixed& b) const;
    bool operator!=(const Fixed& b) const;
    bool operator<(const Fixed& b) const;
    bool operator>(const Fixed& b) const;
    bool operator<=(const Fixed& b) const;
    bool operator>=(const Fixed& b) const;

    // arithmetic
    Fixed operator+(const Fixed& b) const;
    Fixed operator-(const Fixed& b) const;
    Fixed operator*(const Fixed& b) const;
    Fixed operator/(const Fixed& b) const;

    // increment/decrement
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    //min&max
    static Fixed& min(Fixed& a, Fixed& b);
    static  const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);