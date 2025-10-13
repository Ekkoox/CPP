/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:47:52 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/13 16:14:17 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitpoints = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << BOLD << MAGENTA << "====== FRAGTRAP INITIALIZED ======" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << BOLD << MAGENTA << "====== " << other._name << " COPIED ======" << RESET << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap has done a high five alone !" << std::endl;
}

void FragTrap::highFivesGuys_pimp(ClapTrap &target)
{
    std::cout << "FragTrap has done a high five with " << target.getName() << "!" << std::endl;
    std::cout << target.getName() << " does 30 damage more for the 5 next attacks !" << std::endl;
    target.setTemporaryBoost(30, 5);
}
