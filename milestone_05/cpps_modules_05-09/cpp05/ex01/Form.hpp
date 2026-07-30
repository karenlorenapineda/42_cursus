/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:24:39 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/16 22:03:51 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;
public:
	Form(void);
	Form(const std::string& name, int signGrade, int execGrade);
	Form(Form const &src);
	~Form(void);
	
	Form &operator=(Form const &src);

	const std::string&	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void	beSigned(const Bureaucrat& bureaucrat);
	
	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif