/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:40:46 by enschnei          #+#    #+#             */
/*   Updated: 2025/07/29 19:21:43 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie (std::string name) : name(name)     {
    std::cout << this->name << " has been created" << std::endl;
}

Zombie:: ~Zombie() {
    std::cout << this->name << " has been destroy" << std::endl;
}

void Zombie::announce (void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
