/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:14:30 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/31 16:19:55 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(*formCreators[3])(const std::string &target) = {
        [](const std::string &target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string &target) -> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string &target) -> AForm* { return new PresidentialPardonForm(target); }
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Error: Unknown form name \"" << formName << "\"." << std::endl;
    return nullptr;
}
