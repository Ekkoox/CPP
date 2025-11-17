/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/17 16:46:18 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== BASIC BUREAUCRAT TESTS ===" << std::endl;
    try
    {
        Bureaucrat john("John", 42);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== FORM CREATION TESTS ===" << std::endl;
    try
    {
        Form validForm("ValidForm", 50, 30);
        std::cout << validForm << std::endl;

        Form tooHigh("TooHighForm", 0, 10); // Exception attendue
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form tooLow("TooLowForm", 151, 100); // Exception attendue
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== FORM SIGNING TESTS ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 40);
        Bureaucrat bob("Bob", 120);

        Form taxForm("TaxForm", 50, 20);
        Form vacationForm("VacationForm", 130, 80);

        std::cout << taxForm << std::endl;
        std::cout << vacationForm << std::endl;

        std::cout << "\n--- Alice tries to sign TaxForm ---" << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        std::cout << "\n--- Alice tries to sign TaxForm already signed ---" << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;
      
        std::cout << "\n--- Bob tries to sign TaxForm ---" << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
        std::cout << "\n--- Bob tries to sign VacationForm ---" << std::endl;
        bob.signForm(vacationForm);
        std::cout << vacationForm << std::endl;

        std::cout << "\n" << taxForm << std::endl;
        std::cout << vacationForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return (0);
}
