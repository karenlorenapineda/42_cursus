/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:11:18 by kpineda-          #+#    #+#             */
/*   Updated: 2026/07/04 20:11:19 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <cctype>
#include <stack>

class RPN
{
	std::stack<int> _stack;

	bool isOperator(char c) const;

public:
	RPN();
	RPN(const RPN& src);
	~RPN();

	RPN& operator=(const RPN& src);

	int evaluate(const std::string& expression);

};

#endif