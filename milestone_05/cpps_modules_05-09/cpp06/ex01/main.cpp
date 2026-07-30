/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:45:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/24 10:42:47 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    // 1. Create and initialize a Data structure with test values
    Data myData;
    myData.id = 42;
    myData.name = "Check 42";
    myData.value = 3.1416;

    std::cout << "--- ORIGINAL DATA ---" << std::endl;
    std::cout << "Original address  : " << &myData << std::endl;
    std::cout << "ID                : " << myData.id << std::endl;
    std::cout << "Name              : " << myData.name << std::endl;
    std::cout << "Value (double)    : " << myData.value << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;

    // 2. Serialize: Convert the pointer (Data*) to an unsigned integer (uintptr_t)
    std::cout << "Serializing pointer..." << std::endl;
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Integer value (raw): " << raw << " (in hexadecimal: 0x" << std::hex << raw << std::dec << ")" << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;

    // 3. Deserialize: Convert the integer (uintptr_t) back to a pointer (Data*)
    std::cout << "Deserializing integer..." << std::endl;
    Data* ptrDeserializing = Serializer::deserialize(raw);

    std::cout << "--- RECONSTRUCTED DATA ---" << std::endl;
    std::cout << "Returned address  : " << ptrDeserializing << std::endl;
    std::cout << "ID                : " << ptrDeserializing->id << std::endl;
    std::cout << "Name              : " << ptrDeserializing->name << std::endl;
    std::cout << "Value (double)    : " << ptrDeserializing->value << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;

    // 4. Safety verification (The Subject's litmus test)
    if (ptrDeserializing == &myData)
    {
        std::cout << "✅ SUCCESS: The pointers are identical!" << std::endl;
        std::cout << "Serialization and deserialization did not corrupt the memory." << std::endl;
    }
    else
    {
        std::cout << "❌ ERROR: The pointers DO NOT match." << std::endl;
    }

    return 0;
}