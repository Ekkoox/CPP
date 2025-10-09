/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:02:24 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/09 16:58:45 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

Claptrap::Claptrap(std::string name) {
    this->_name = name;
    std::cout << this->_name << " default constructor called" << std::endl;
    this->_hitpoints = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;
}

Claptrap::~Claptrap() {
    std::cout << this->_name << " destructor called" << std::endl;
}

void Claptrap::attack(const std::string& target){
    if (this->_energy_points > 0 && this->_hitpoints > 0) {
        this->_energy_points--;
        std::cout << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    } else {
        std::cout << this->_name << " has no energy points or hitpoints left to attack." << std::endl;
    }
}

void Claptrap::takeDamage(unsigned int amount) {
    if (amount > this->_hitpoints) {
        amount = this->_hitpoints;
    }
    this->_hitpoints -= amount;
    std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void Claptrap::beRepaired(unsigned int amount) {
    if (this->_energy_points > 0 && this->_hitpoints > 0) {
        this->_hitpoints += amount;
        this->_energy_points--;
        std::cout << this->_name << " is repaired by " << amount << " points!" << std::endl;
    } else {
        std::cout << this->_name << " has no energy points or hitpoints left to be repaired." << std::endl;
    }
}

void Claptrap::showlifepoints() {
    std::cout << this->_name << " has " << this->_hitpoints << " HP left." << std::endl;
}