/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:42:36 by kpineda-          #+#    #+#             */
/*   Updated: 2026/01/18 20:50:37 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = num << this->fractional_bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(num * (1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void )const
{
    return ((float)this->fixed_point / (float)(1 << this->fractional_bits));
}

int Fixed::toInt( void )const
{
    return (this->fixed_point >> this->fractional_bits);
}

int Fixed::getRawBits( void ) const
{
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

Fixed &Fixed::operator=(const Fixed &cpy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_point = cpy.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}