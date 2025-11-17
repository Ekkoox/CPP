/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:04 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/17 16:35:42 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw std::out_of_range("Grade too high");
    if (grade > 150)
        throw std::out_of_range("Grade too low");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const 
{
    return (this->_name);
}

int Bureaucrat::getGrade() const 
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low exception";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
