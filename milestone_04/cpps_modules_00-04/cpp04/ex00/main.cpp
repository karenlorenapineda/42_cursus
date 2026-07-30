/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:36:47 by kpineda-          #+#    #+#             */
/*   Updated: 2026/02/19 18:33:55 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "--------------------------------------" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << wrong->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	
	k->makeSound();
	wrong->makeSound();

	delete k;
	delete j;
	delete i;
	delete wrong;
	delete meta;
	
	return 0;
}
