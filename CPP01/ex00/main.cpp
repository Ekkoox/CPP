/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:54:16 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/16 13:03:15 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() 
{
    Zombie *zombie = newZombie ("Zombie *hungry*");
    Zombie *zombie2 = newZombie ("Zombie *brainless*");
    zombie->announce();
    zombie2->announce();
    randomChump("Zombie *strong one*");
    delete zombie;
    delete zombie2;
    return (0);
}
