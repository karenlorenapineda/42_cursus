/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:11:21 by kpineda-          #+#    #+#             */
/*   Updated: 2026/07/04 20:15:13 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

RPN::RPN()
{

}

RPN::RPN(const RPN& src) : _stack(src._stack)
{

}

RPN::~RPN()
{

}

RPN& RPN::operator=(const RPN& src)
{
	if(this != &src)
		_stack = src._stack;
	return *this;
}

int RPN::evaluate(const std::string& expression)
{
	while (!_stack.empty()) _stack.pop();

	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];

		if (c == ' ') continue;

		if (std::isdigit(c))
			_stack.push(c - '0');

		else if (isOperator(c))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();

			switch (c)
			{
			case '+':
				_stack.push(a + b);
				break;

			case '-':
				_stack.push(a - b);
				break;

			case '*':
				_stack.push(a * b);
				break;

			case '/':
				if (b == 0)
					throw std::runtime_error("Error");
				_stack.push(a / b);
				break;
			}
		}
		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}