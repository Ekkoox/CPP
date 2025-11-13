/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:14:30 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/13 16:24:13 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
    (void)src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return *this;
}

AForm *Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found exception";
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(*formCreators[3])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }
    throw Intern::FormNotFoundException();
}