/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:46:06 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/14 12:47:34 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
    std::cout << BOLD << RED << "====== INITIALIZED OF THE GAME ======" << RESET << std::endl;
    ClapTrap claptrap = ClapTrap("ClapTrap");
    claptrap.showLifePoints();
    ScavTrap scavtrap = ScavTrap("ScavTrap");
    scavtrap.showLifePoints();
    ClapTrap bandit = ClapTrap("Bandit");
    bandit.showLifePoints();
    ScavTrap Bandit_guardian = ScavTrap("Bandit Guardian");
    Bandit_guardian.showLifePoints();
    FragTrap fragtrap = FragTrap("FragTrap");
    fragtrap.showLifePoints();
    ClapTrap pnJ = ClapTrap();
    pnJ.showLifePoints();

    std::cout << BOLD << MAGENTA << "====== ClapTrap BATTLE PHASE ======" << RESET << std::endl;
    for (int i = 0; i < 13; i++)
    {
        claptrap.attack("Bandit");
        claptrap.showEnergyPoints();
        if (claptrap.getEnergyPoints() > 0) 
            bandit.takeDamage(claptrap.getAttackDamage());
    }

    std::cout << BOLD << MAGENTA << "====== Bandit REPAIR PHASE ======" << RESET << std::endl;
    if (bandit.getHitPoints() > 0)
        bandit.beRepaired(20);
    bandit.showLifePoints();
    
    std::cout << BOLD << MAGENTA << "====== Bandit BATTLE PHASE ======" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
    {
        bandit.attack("Claptrap");
        bandit.showEnergyPoints();
        if (bandit.getEnergyPoints() > 0)
            claptrap.takeDamage(bandit.getAttackDamage());
    }
    
    std::cout << BOLD << MAGENTA << "====== ClapTrap REPAIR PHASE ======" << RESET << std::endl;
    if (claptrap.getHitPoints() > 0)
        claptrap.beRepaired(30);
    
    std::cout << BOLD << MAGENTA << "====== ScavTrap BATTLE PHASE ======" << RESET << std::endl;
    while(bandit.getHitPoints() >= 0 || scavtrap.getEnergyPoints() > 0)
    {
        if (bandit.getHitPoints() == 0)
        {
            std::cout << BOLD << CYAN << "Bandit is dead ! " << RESET << std::endl;
            break ;
        }
        scavtrap.attack("Bandit");
        scavtrap.showEnergyPoints();
        if (scavtrap.getEnergyPoints() > 0) 
            bandit.takeDamage(scavtrap.getAttackDamage());
    }
    
    std::cout << BOLD << MAGENTA << "====== Bandit REPAIR PHASE ======" << RESET << std::endl;
        bandit.beRepaired(20);
    if (bandit.getHitPoints() > 0)
        bandit.showLifePoints();

    std::cout << BOLD << MAGENTA << "====== ScavTrap GUARDIAN MODE ======" << RESET << std::endl;
    if (scavtrap.getHitPoints() > 0)
    {
        scavtrap.setGuardMode(true);
        scavtrap.guardGate();
    }
    else
        std::cout << RED << "ScavTrap is dead and cannot enter Guardian Mode." << RESET << std::endl;

    std::cout << BOLD << MAGENTA << "====== Bandit Guardian BATTLE PHASE ======" << RESET << std::endl;
    bool guardModeChanged = false;
    while(scavtrap.getEnergyPoints() >= 0 || Bandit_guardian.getHitPoints() > 0)
    {
        if (scavtrap.getHitPoints() == 0)
        {
            std::cout << BOLD << CYAN << "Scavtrap is dead ! " << RESET << std::endl;
            break ;
        }
        Bandit_guardian.attack("Scavtrap");
        Bandit_guardian.showEnergyPoints();
        if (Bandit_guardian.getEnergyPoints() > 0) 
            scavtrap.takeDamage(Bandit_guardian.getAttackDamage());
        if (scavtrap.getHitPoints() <= 50 && !guardModeChanged)
        {
            scavtrap.setGuardMode(false);
            scavtrap.guardGate();
            guardModeChanged = true;
        }
    }
    
    std::cout << BOLD << MAGENTA << "====== Fragtrap BOOSTING PHASE ======" << RESET << std::endl;
    fragtrap.highFivesGuys(); //Mandatory part
    fragtrap.highFivesGuys_pimp(claptrap); //Pimp part
    claptrap.showEnergyPoints();

    std::cout << BOLD << MAGENTA << "====== ClapTrap BATTLE PHASE ======" << RESET << std::endl;
    while(claptrap.getEnergyPoints() > 0 && Bandit_guardian.getHitPoints() > 0)
    {
        claptrap.attack("Bandit Guardian");
        claptrap.showEnergyPoints();
        if (claptrap.getEnergyPoints() > 0) 
            Bandit_guardian.takeDamage(claptrap.getAttackDamage());
    }
    if (Bandit_guardian.getHitPoints() > 0)
        Bandit_guardian.showLifePoints();
    else
        std::cout << BOLD << CYAN << "Bandit Guardian is dead ! " << RESET << std::endl;

    std::cout << BOLD << MAGENTA << "====== Bandit Guardian GUARD MODE ======" << RESET << std::endl;
    if (Bandit_guardian.getHitPoints() > 0)
    {
        Bandit_guardian.setGuardMode(true);
        Bandit_guardian.guardGate();
    }
    else
        std::cout << RED << "Bandit Guardian is dead and cannot enter Guardian Mode." << RESET << std::endl;

        
    std::cout << BOLD << MAGENTA << "====== END OF THE BATTLE ======" << RESET << std::endl;
    claptrap.showLifePoints();
    bandit.showLifePoints();
    scavtrap.showLifePoints();
    Bandit_guardian.showLifePoints();
    fragtrap.showLifePoints();
    
    std::cout << BOLD << RED << "====== END OF THE GAME ======" << RESET << std::endl;
    return (0);
}
