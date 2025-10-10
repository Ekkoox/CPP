/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:24:17 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/10 18:31:24 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_name = "Scavtrap";
    this->_hitpoints = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_guard_mode = false;
    std::cout << BOLD << MAGENTA << "====== SCAVTRAP INITIALIZED ======" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_guard_mode = false;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << BOLD << MAGENTA << "====== " << other._name << " COPIED ======" << RESET << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
        this->_guard_mode = other._guard_mode;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << BOLD << MAGENTA << "====== " << this->_name << " DESTRUCTED ======" << RESET << std::endl;
}

void ScavTrap::setGuardMode(bool mode)
{
    this->_guard_mode = mode;
}

bool ScavTrap::getGuardMode() const
{
    return this->_guard_mode;
}

void ScavTrap::guardGate()
{
    if (this->_guard_mode == true)
        std::cout << BOLD << YELLOW << this->_name << " is now in GATE mode ! Damage taken will be reduced by 10." << RESET << std::endl;
    if (this->_guard_mode == false)
        std::cout << BOLD << YELLOW << this->_name << " is now out of GATE mode ! Damage taken will be normal." << RESET << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (this->_guard_mode)
    {
        if (amount >= 10)
            amount -= 10;
        else
            amount = 0;
    }

    if (amount > this->_hitpoints)
        amount = this->_hitpoints;

    this->_hitpoints -= amount;

    std::cout << this->_name << " takes " << RED << amount << RESET << " points of damage!" << BOLD << GREEN << " (HP left: " << this->_hitpoints << ")" << RESET << std::endl;

}
