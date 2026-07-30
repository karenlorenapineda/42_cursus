/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:05:35 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/29 11:05:36 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	T*				_array;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& src);
	~Array();

	Array& operator=(const Array& src);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size() const;

};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{

}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{

}

template <typename T>
Array<T>::Array(const Array& src) : _array(NULL), _size(0)
{
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		delete[] _array;
		_size = src._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}



#endif