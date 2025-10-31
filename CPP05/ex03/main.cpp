/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/31 18:00:38 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
{
    try
    {
        std::cout << "===== TEST 1: SHRUBBERY CREATION =====" << std::endl;
        Bureaucrat john("John", 100);
        ShrubberyCreationForm shrub("garden");

        std::cout << shrub << std::endl;
        john.signForm(shrub);
        // john.executeForm(shrub); // devrait réussir et créer un fichier garden_shrubbery
        std::cout << std::endl;


        std::cout << "===== TEST 2: ROBOTOMY REQUEST =====" << std::endl;
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");

        std::cout << robot << std::endl;
        alice.signForm(robot);
        // alice.signForm(robot); // 50% chance de succès
        std::cout << std::endl;


        std::cout << "===== TEST 3: PRESIDENTIAL PARDON =====" << std::endl;
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm pardon("Marvin");

        std::cout << pardon << std::endl;
        boss.signForm(pardon);
        // boss.signForm(pardon); // devrait réussir et afficher le message de pardon
        std::cout << std::endl;


        std::cout << "===== TEST 4: EXECUTION BEFORE SIGNING =====" << std::endl;
        Bureaucrat intern("Intern", 50);
        ShrubberyCreationForm unsignedForm("backyard");

        std::cout << unsignedForm << std::endl;
        intern.signForm(unsignedForm);
        std::cout << unsignedForm << std::endl;
        unsignedForm.execute(intern);
        std::cout << std::endl;


        std::cout << "===== TEST 5: GRADE TOO LOW =====" << std::endl;
        Bureaucrat newbie("Newbie", 150);
        RobotomyRequestForm hardForm("Terminator");

        std::cout << hardForm << std::endl;
        newbie.signForm(hardForm);   // trop bas
        // newbie.signForm(hardForm); // trop bas aussi
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
{
    try
    {
        std::cout << "\n===== TEST 6: FORM CREATION WITH INVALID GRADES =====" << std::endl;
        ShrubberyCreationForm invalidForm("invalid");   
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
    return 0;
}
