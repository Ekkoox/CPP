/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:59:25 by enschnei          #+#    #+#             */
/*   Updated: 2025/08/04 19:09:56 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

const std::string &Weapon::getType(void) const
{
    return (this->_type);
}

