/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:15:36 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/13 12:41:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
}

const std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecuteGrade() const
{
    return _executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    if (_isSigned)
        throw std::runtime_error("Form is already signed");
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Exception: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Exception: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form \"" << form.getName() << "\", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade()
       << ", Signed: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
