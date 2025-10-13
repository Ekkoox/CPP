/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:01:52 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/13 15:45:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
    std::cout << BOLD << RED << "===== INITIALIZED OF THE GAME =====" << RESET << std::endl;
    ClapTrap claptrap = ClapTrap("ClapTrap");
    claptrap.showLifePoints();
    ClapTrap bandit = ClapTrap("Bandit");
    bandit.showLifePoints();
    ClapTrap pnJ = ClapTrap();
    pnJ.showLifePoints();

    std::cout << BOLD << MAGENTA << "====== ClapTrap BATTLE PHASE ======" << RESET << std::endl;
    for (int i = 0; i < 13; i++)
    {
        claptrap.attack("Bandit");
        claptrap.showEnergyPoints();
        if (claptrap.getEnergyPoints() > 0) 
            bandit.takeDamage(0);
    }
    bandit.showLifePoints();
    std::cout << BOLD << MAGENTA << "====== Bandit BATTLE PHASE ======" << RESET << std::endl;
    bandit.attack("Claptrap");
    claptrap.takeDamage(0);
    claptrap.showLifePoints();
    std::cout << BOLD << MAGENTA << "====== ClapTrap REPAIR PHASE ======" << RESET << std::endl;
    claptrap.beRepaired(3);
    std::cout << BOLD << MAGENTA << "====== Bandit REPAIR PHASE ======" << RESET << std::endl;
    bandit.beRepaired(2);
    std::cout << BOLD << MAGENTA << "====== END OF THE BATTLE ======" << RESET << std::endl;
    claptrap.showLifePoints();
    bandit.showLifePoints();

    std::cout << BOLD << RED << "====== END OF THE GAME ======" << RESET << std::endl;
    return (0);
}