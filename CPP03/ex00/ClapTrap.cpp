/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:02:24 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/09 19:08:42 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << BOLD << MAGENTA << "====== PNJ INITIALIZED ======" << RESET << std::endl;
    this->_name = "PNJ";
    this->_hitpoints = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    this->_name = name;
    std::cout << BOLD << MAGENTA << "====== " << this->_name << " INITIALIZED ======" << RESET << std::endl;
    this->_hitpoints = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;
}

ClapTrap::~ClapTrap() {
    std::cout << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (this->_energy_points > 0 && this->_hitpoints > 0) {
        this->_energy_points--;
        std::cout << BOLD <<this->_name << " attacks " << target << ", causing " << RED <<this->_attack_damage << RESET << BOLD << " points of damage!" << RESET << std::endl;
    } else {
        std::cout << RED << this->_name << " has no energy points or hitpoints left to attack." << RESET << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount > this->_hitpoints) {
        amount = this->_hitpoints;
    }
    this->_hitpoints -= amount;
    std::cout << this->_name << " takes " << RED << amount << RESET << " points of damage!"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energy_points > 0 && this->_hitpoints > 0) {
        this->_hitpoints += amount;
        this->_energy_points--;
        std::cout << GREEN << this->_name << " is repaired by " << amount << " points!" << std::endl;
    } else {
        std::cout << RED << this->_name << " has no energy points or hitpoints left to be repaired." << RESET <<std::endl;
    }
}

void ClapTrap::showLifePoints() {
    std::cout << this->_name << " has " << GREEN << this->_hitpoints << RESET << " HP left."<< std::endl;
}

void ClapTrap::showEnergyPoints() {
    std::cout << this->_name << " has " << CYAN << this->_energy_points << RESET << " EP left." << std::endl;
}