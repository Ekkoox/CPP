/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/13 16:25:57 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(void)
{
    {
        try
        {
            Bureaucrat MacronDemission("Manu", 1);
            std::cout << MacronDemission << std::endl;
            // Create form
            Intern  SomeRandomIntern;
            AForm   *InternsForm;
            // InternsForm = SomeRandomIntern.makeForm("presidential pardon request", "tom");
            InternsForm = SomeRandomIntern.makeForm("presidential pardon", "tom");
            MacronDemission.signForm(*InternsForm);
            InternsForm->execute(MacronDemission);
            std::cout << "////// Intern creates non existing form //////" << std::endl;
            delete (InternsForm);
            AForm   *weirdForm;
            weirdForm = SomeRandomIntern.makeForm("become emperor", "intern");
            MacronDemission.signForm(*weirdForm);
            weirdForm->execute(MacronDemission);
            delete (weirdForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error : " << e.what() << std::endl;
        }
    }
    return (0);
}
