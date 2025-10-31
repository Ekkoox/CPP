/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/31 17:56:01 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // {
    // std::cout << "===== TEST 1: SHRUBBERY CREATION =====" << std::endl;
    // try
    // {
    //     Bureaucrat john("John", 1);
    //     ShrubberyCreationForm shrub("garden");
    //     std::cout << shrub << std::endl;
    //     john.signForm(shrub);
    //     std::cout << shrub << std::endl;
    //     john.executeForm(shrub);
    //     std::cout << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // std::cout << "===== TEST 2: SHRUBBERY EXCEPTION =====" << std::endl;
    // try
    // {
    //     Bureaucrat john("John", 150);
    //     ShrubberyCreationForm shrub("garden");
    //     std::cout << shrub << std::endl;
    //     john.signForm(shrub);
    //     std::cout << shrub << std::endl;
    //     john.executeForm(shrub);
    //     std::cout << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // std::cout << "===== TEST 3: SHRUBBERY SIGN BUT NOT EXECUTE =====" << std::endl;
    // try
    // {
    //     Bureaucrat john("John", 1);
    //     Bureaucrat boss("Boss", 150);
    //     ShrubberyCreationForm shrub("garden");
    //     std::cout << shrub << std::endl;
    //     john.signForm(shrub);
    //     std::cout << shrub << std::endl;
    //     boss.executeForm(shrub);
    //     std::cout << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    
    // {
    //     srand(time(0));
    //     std::cout << "===== TEST 1: ROBOTOMY REQUEST =====" << std::endl;
    //     try
    //     {
    //         Bureaucrat alice("Alice", 1);
    //         RobotomyRequestForm robotomy("Bob");
    //         std::cout << robotomy << std::endl;
    //         alice.signForm(robotomy);
    //         std::cout << robotomy << std::endl;
    //         alice.executeForm(robotomy);
    //         std::cout << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }
    //     std::cout << "===== TEST 2: ROBOTOMY EXCEPTION =====" << std::endl;
    //     try
    //     {
    //         Bureaucrat alice("Alice", 150);
    //         RobotomyRequestForm robotomy("Bob");
    //         std::cout << robotomy << std::endl;
    //         alice.signForm(robotomy);
    //         std::cout << robotomy << std::endl;
    //         alice.executeForm(robotomy);
    //         std::cout << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }
    //     std::cout << "===== TEST 3: ROBOTOMY SIGN BUT NOT EXECUTE =====" << std::endl;
    //     try
    //     {
    //         Bureaucrat alice("Alice", 1);
    //         Bureaucrat boss("Boss", 150);
    //         RobotomyRequestForm robotomy("Bob");
    //         std::cout << robotomy << std::endl;
    //         alice.signForm(robotomy);
    //         std::cout << robotomy << std::endl;
    //         boss.executeForm(robotomy);
    //         std::cout << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }
    // }
    
    // {
    //     std::cout << "===== TEST 1: PRESIDENTIAL PARDON =====" << std::endl;
    //     try
    //     {
    //         Bureaucrat frank("Frank", 1);
    //         PresidentialPardonForm pardon("George");
    //         std::cout << pardon << std::endl;
    //         frank.signForm(pardon);
    //         std::cout << pardon << std::endl;
    //         frank.executeForm(pardon);
    //         std::cout << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }
    //     std::cout << "===== TEST 2: PRESIDENTIAL PARDON EXCEPTION =====" << std::endl;
    //     try
    //     {
    //         Bureaucrat frank("Frank", 150);
    //         PresidentialPardonForm pardon("George");
    //         std::cout << pardon << std::endl;
    //         frank.signForm(pardon);
    //         std::cout << pardon << std::endl;
    //         frank.executeForm(pardon);
    //         std::cout << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }
    //     std::cout << "===== TEST 3: PRESIDENTIAL PARDON SIGN BUT NOT EXECUTE =====" << std::endl;
    //     try
    //     {
    //         Bureaucrat frank("Frank", 1);
    //         Bureaucrat boss("Boss", 150);
    //         PresidentialPardonForm pardon("George");
    //         std::cout << pardon << std::endl;
    //         frank.signForm(pardon);
    //         std::cout << pardon << std::endl;
    //         boss.executeForm(pardon);
    //         std::cout << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }
    // }
    return (0);
}
