/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:05:24 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/29 11:05:25 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    // Test default constructor
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    // Test size constructor
    Array<int> arr(5);
    std::cout << "Size 5 array: " << arr.size() << std::endl;

    // Test value initialization
    std::cout << "Initial values: ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Test modification
    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i * 10;
    }
    std::cout << "After modification: ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Test deep copy
    Array<int> copy = arr;
    copy[0] = 999;
    std::cout << "Original[0]: " << arr[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    // Test bounds checking
    try {
        arr[100] = 42;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test with different type
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

	const Array<int> const_arr(5);
	// const_arr[0] = 42; // This shouldn't compile if you uncomment it (good)
	std::cout << "Const array val: " << const_arr[0] << std::endl; // This should work perfectly

    return 0;
}