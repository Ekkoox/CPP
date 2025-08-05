/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:26:56 by enschnei          #+#    #+#             */
/*   Updated: 2025/08/05 17:29:13 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack(void) const
{
    if (!this->_weapon)
        std::cout << this->_name << " no weapon " << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}