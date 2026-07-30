/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:06:02 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/29 11:06:03 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) 
{
	int a = 5;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// Test equal case - should return second
    int x = 5, y = 5;
    std::cout << "Equal test: &x=" << &x << ", &y=" << &y << std::endl;
    std::cout << "min returns: " << &(::min(x, y)) << std::endl;
    std::cout << "max returns: " << &(::max(x, y)) << std::endl;
    // Should print &y for both!

	return 0;
}