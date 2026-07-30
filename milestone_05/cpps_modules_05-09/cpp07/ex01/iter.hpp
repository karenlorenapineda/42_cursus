/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:05:46 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/29 11:05:47 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>

void iter(T* array, size_t length, void (*func)(T&))
{
	for(size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>

void iter(T* array, size_t length, void (*func)(T const&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
#endif