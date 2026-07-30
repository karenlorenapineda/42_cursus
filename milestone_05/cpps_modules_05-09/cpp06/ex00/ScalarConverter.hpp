/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:27:00 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/24 09:53:31 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <string>
#include <cctype>
#include <cmath>

class ScalarConverter
{
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter(void);

	ScalarConverter& operator=(const ScalarConverter& src);
	
public:
	static void convert(const std::string& literal);
};

#endif