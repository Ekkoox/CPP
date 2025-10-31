/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:20:21 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/29 18:17:52 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSignGrade())
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!this->isSigned())
        throw std::runtime_error("ShrubberyCreationForm Exception: Form not signed");

    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::runtime_error("ShrubberyCreationForm Exception: Could not open file");

    outfile <<
"            .        +          .      .          .\n"
"     .            _        .                    .\n"
"  ,              /;-._,-.____        ,-----.__\n"
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
"                      ,    `./  \\:. `.   )==-'  .\n"
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
"              \\:  `  X` _| _,\\/'   .-'\n"
".               \":._:`\\____  /:'  /      .           .\n"
"                    \\::.  :\\/:'  /              +\n"
"   .                 `.:.  /:'  }      .\n"
"           .           ):_(:;   \\           .\n"
"                      /:. _/ ,  |\n"
"                   . (|::.     ,`                  .\n"
"     .                |::.    {\\\n"
"                      |::.:\\  \\ `.\n"
"                      |:::(\\    |\n"
"              O       |:::/{ }  |                  (o\n"
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~\n";

    outfile.close();
    std::cout << "Shrubbery successfully created: " << this->_target + "_shrubbery" << std::endl;
}

