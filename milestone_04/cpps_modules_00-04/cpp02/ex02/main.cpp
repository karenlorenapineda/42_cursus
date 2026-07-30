/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:23:32 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/03 20:38:50 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}


/*
#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    std::cout << "===== CONSTRUCTORES =====" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n===== ASIGNACION =====" << std::endl;
    a = Fixed(123.456f);
    std::cout << "a = " << a << std::endl;

    std::cout << "\n===== toInt / toFloat =====" << std::endl;
    std::cout << "a toInt = " << a.toInt() << std::endl;
    std::cout << "c toInt = " << c.toInt() << std::endl;

    std::cout << "\n===== OPERADORES ARITMETICOS =====" << std::endl;
    Fixed x(5.5f);
    Fixed y(2);

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    std::cout << "\n===== OPERADORES DE COMPARACION =====" << std::endl;
    std::cout << "x > y  = " << (x > y) << std::endl;
    std::cout << "x < y  = " << (x < y) << std::endl;
    std::cout << "x >= y = " << (x >= y) << std::endl;
    std::cout << "x <= y = " << (x <= y) << std::endl;
    std::cout << "x == y = " << (x == y) << std::endl;
    std::cout << "x != y = " << (x != y) << std::endl;

    std::cout << "\n===== INCREMENTOS / DECREMENTOS =====" << std::endl;
    Fixed z;

    std::cout << "z = " << z << std::endl;
    std::cout << "++z = " << ++z << std::endl;
    std::cout << "z++ = " << z++ << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "--z = " << --z << std::endl;
    std::cout << "z-- = " << z-- << std::endl;
    std::cout << "z = " << z << std::endl;

    std::cout << "\n===== MIN / MAX =====" << std::endl;
    Fixed m1(3.14f);
    Fixed m2(2.71f);

    std::cout << "min = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max = " << Fixed::max(m1, m2) << std::endl;

    return 0;
}
*/
/*
#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    std::cout << "========== DEFENSA FIXED ==========" << std::endl;

    std::cout << "\n--- Incrementos críticos ---" << std::endl;
    Fixed a;

    std::cout << "a      = " << a << std::endl;
    std::cout << "a++    = " << a++ << std::endl;
    std::cout << "after = " << a << std::endl;
    std::cout << "++a    = " << ++a << std::endl;
    std::cout << "after = " << a << std::endl;

    std::cout << "\n--- Retorno por referencia (++) ---" << std::endl;
    Fixed b;
    Fixed &ref = ++b;
    ref++;
    std::cout << "b = " << b << std::endl;

    std::cout << "\n--- Comparaciones exactas ---" << std::endl;
    Fixed x(1.5f);
    Fixed y(1.5f);
    Fixed z(1.50390625f);

    std::cout << "(x == y) = " << (x == y) << std::endl;
    std::cout << "(x != z) = " << (x != z) << std::endl;
    std::cout << "(x < z)  = " << (x < z) << std::endl;
    std::cout << "(z > y)  = " << (z > y) << std::endl;

    std::cout << "\n--- Operaciones encadenadas ---" << std::endl;
    Fixed r = Fixed(5.05f) * Fixed(2) + Fixed(1);
    std::cout << "r = " << r << std::endl;

    std::cout << "\n--- Negativos ---" << std::endl;
    Fixed n1(-10);
    Fixed n2(-2.5f);

    std::cout << "n1 = " << n1 << std::endl;
    std::cout << "n2 = " << n2 << std::endl;
    std::cout << "n1 + n2 = " << (n1 + n2) << std::endl;
    std::cout << "n1 * n2 = " << (n1 * n2) << std::endl;

    std::cout << "\n--- Min / Max (const) ---" << std::endl;
    Fixed const c1(42.42f);
    Fixed const c2(42.4219f);

    std::cout << "min = " << Fixed::min(c1, c2) << std::endl;
    std::cout << "max = " << Fixed::max(c1, c2) << std::endl;

    std::cout << "\n--- Comparación post-operaciones ---" << std::endl;
    Fixed t(1);

    if (t++ > Fixed(1))
        std::cout << "ERROR" << std::endl;
    else
        std::cout << "OK" << std::endl;

    if (++t > Fixed(1))
        std::cout << "OK" << std::endl;
    else
        std::cout << "ERROR" << std::endl;

    std::cout << "\n========== FIN DEFENSA ==========" << std::endl;
    return 0;
}
*/