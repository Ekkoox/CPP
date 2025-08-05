/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:26:40 by enschnei          #+#    #+#             */
/*   Updated: 2025/08/05 16:20:50 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{ 
}

void HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}