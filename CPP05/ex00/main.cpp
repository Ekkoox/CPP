/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/12 13:15:35 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "=== NORMAL CREATION ===" << std::endl;
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

    std::cout << "\n=== TEST TOO HIGH ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 0); // trop haut
        std::cout << boss << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST TOO LOW ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 151); // trop bas
        std::cout << intern << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST LIMITS ===" << std::endl;
    try
    {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
