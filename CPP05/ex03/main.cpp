/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/17 16:56:39 by enschnei         ###   ########.fr       */
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
            Bureaucrat Squirtle("Squirtle", 1);
            std::cout << Squirtle << std::endl;
            Intern  SomeRandomPokemon;
            AForm   *PokemonForm;
            PokemonForm = SomeRandomPokemon.makeForm("presidential pardon", "tom");
            Squirtle.signForm(*PokemonForm);
            PokemonForm->execute(Squirtle);
            delete (PokemonForm);
            AForm   *weirdForm;
            std::cout << "////// Pokemon creates non existing form //////" << std::endl;
            weirdForm = SomeRandomPokemon.makeForm("become emperor", "intern");
            Squirtle.signForm(*weirdForm);
            weirdForm->execute(Squirtle);
            delete (weirdForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error : " << e.what() << std::endl;
        }
    }
    return (0);
}
