/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:45:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/24 10:37:46 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void runTest(const std::string& literal) {
    std::cout << "========================================" << std::endl;
    std::cout << "Testing literal: \"" << literal << "\"" << std::endl;
    std::cout << "========================================" << std::endl;
    ScalarConverter::convert(literal);
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }


    std::cout << "--- STARTING AUTOMATIC TESTS ---" << std::endl << std::endl;

    // 1. CHAR test
    runTest("a");
    runTest("Z");

    // 2. INT
    runTest("0");
    runTest("42");
    runTest("-42");
    runTest("2147483647"); // INT_MAX
    runTest("2147483648"); // Overflow 

    // 3. FLOAT test
    runTest("0.0f");
    runTest("4.2f");
    runTest("-4.2f");

    // 4. DOUBLE test
    runTest("0.0");
    runTest("42.42");
    runTest("-42.42");

    // 5. Pseudo-literals
    runTest("nan");
    runTest("nanf");
    runTest("+inf");
    runTest("-inf");
    runTest("+inff");
    runTest("-inff");

    // 6. Invalid case
    runTest("abc");
    runTest("42.42f42");
    runTest("");

    std::cout << "--- TESTS FINISHED ---" << std::endl;
    return 0;
}