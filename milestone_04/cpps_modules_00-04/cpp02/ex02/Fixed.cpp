/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:42:36 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/03 20:33:45 by kpineda-         ###   ########.fr       */
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
    this->fixed_point = static_cast<int>(roundf(num * (1 << this->fractional_bits)));
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
    return (static_cast<float>(fixed_point) / (1 << this->fractional_bits));
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

// comparision

bool Fixed::operator==(const Fixed& b) const
{
    return(this->fixed_point == b.fixed_point); 
}

bool Fixed::operator!=(const Fixed& b) const
{
    return(this->fixed_point != b.fixed_point); 
}

bool Fixed::operator<(const Fixed& b) const
{
    return(this->fixed_point < b.fixed_point); 
}

bool Fixed::operator>(const Fixed& b) const
{
    return(this->fixed_point > b.fixed_point); 
}

bool Fixed::operator<=(const Fixed& b) const
{
    return(this->fixed_point <= b.fixed_point); 
}

bool Fixed::operator>=(const Fixed& b) const
{
    return(this->fixed_point >= b.fixed_point); 
}

// arithmetic

Fixed Fixed::operator+(const Fixed& b) const
{
    Fixed value;
    value.fixed_point = this->fixed_point + b.fixed_point; 
    return(value);
}

Fixed Fixed::operator-(const Fixed& b) const
{
    Fixed value;
    value.fixed_point = this->fixed_point - b.fixed_point; 
    return(value);
}

Fixed Fixed::operator*(const Fixed& b) const
{
    Fixed value;
    value.fixed_point = this->fixed_point * b.fixed_point;
    value.fixed_point = value.fixed_point >> fractional_bits;
    return(value);
}

Fixed Fixed::operator/(const Fixed& b) const
{
    Fixed value;
    value.fixed_point = (this->fixed_point << fractional_bits ) / b.fixed_point;
    return(value);
}

// increment/decrement

Fixed& Fixed::operator++()
{
    ++this->fixed_point;
    return(*this);
}

Fixed& Fixed::operator--()
{
    --this->fixed_point;
    return(*this); 
}

Fixed Fixed::operator++(int)
{
    Fixed temp;
    temp = *this;
    ++this->fixed_point;
    return(temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp;
    temp = *this;
    --this->fixed_point;
    return(temp);
}

//min&max
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return(a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return(a < b) ? a : b; 
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return(a > b) ? a : b; 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return(a > b) ? a : b; 
}
