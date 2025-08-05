/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:22:23 by enschnei          #+#    #+#             */
/*   Updated: 2025/08/01 17:42:36 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": NIIIIIEEEEEEEEEELL" << std::endl;
}
