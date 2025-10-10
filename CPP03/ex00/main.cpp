/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:01:52 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:54 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
    ClapTrap claptrap = ClapTrap("ClapTrap");
    claptrap.showLifePoints();
    ClapTrap ennemi = ClapTrap("Bandit");
    ennemi.showLifePoints();
    ClapTrap pnJ = ClapTrap();
    pnJ.showLifePoints();

    std::cout << BOLD << MAGENTA << "====== ClapTrap BATTLE PHASE ======" << RESET << std::endl;
    for (int i = 0; i < 13; i++)
    {
        claptrap.attack("Bandit");
        claptrap.showEnergyPoints();
        if (claptrap.getEnergyPoints() > 0) 
            ennemi.takeDamage(0);
    }
    ennemi.showLifePoints();
    std::cout << BOLD << MAGENTA << "====== Bandit BATTLE PHASE ======" << RESET << std::endl;
    ennemi.attack("Claptrap");
    claptrap.takeDamage(0);
    claptrap.showLifePoints();
    std::cout << BOLD << MAGENTA << "====== ClapTrap REPAIR PHASE ======" << RESET << std::endl;
    claptrap.beRepaired(3);
    std::cout << BOLD << MAGENTA << "====== Bandit REPAIR PHASE ======" << RESET << std::endl;
    ennemi.beRepaired(2);
    std::cout << BOLD << MAGENTA << "====== END OF THE BATTLE ======" << RESET << std::endl;
    claptrap.showLifePoints();
    ennemi.showLifePoints();
    std::cout << BOLD << MAGENTA << "====== DESTRUCTOR ======" << RESET << std::endl;
    return (0);
}