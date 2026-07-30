/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:05:50 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/29 11:05:51 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const& elem) {
    std::cout << "[" << elem << "] ";
}

template <typename T>
void increment(T& elem) {
    elem++;
}

int main() {
    // Test with int array
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    iter(numbers, 5, increment<int>);
    std::cout << "After increment: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    // Test with string array
    std::string words[] = {"hello", "world", "test"};
    std::cout << "String array: ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;

    // Test with empty array
    int empty[1] = {0};
    iter(empty, 0, print<int>);  // Should do nothing
    std::cout << "Empty test passed" << std::endl;

    return 0;
}