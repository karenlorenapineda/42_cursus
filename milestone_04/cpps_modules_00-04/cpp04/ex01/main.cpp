/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:36:47 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/19 18:33:31 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 10;
    Animal* animals[size];

    std::cout << "--- CREATING ANIMALS ---" << std::endl;
    for (int i = 0; i < size; i++) 
    {
        if (i < size / 2) 
            animals[i] = new Dog();
        else 
            animals[i] = new Cat();
        std::cout << "Animal [" << i << "] created." << std::endl;
    }

    std::cout << "\n--- TESTING SOUNDS ---" << std::endl;
    for (int i = 0; i < size; i++) 
        animals[i]->makeSound();
    std::cout << "\n--- DELETING ANIMALS ---" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n--- TEST ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* k = new Cat();
    
    delete j;
    delete k;

    return 0;
}