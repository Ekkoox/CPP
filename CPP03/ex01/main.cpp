/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:24:28 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/09 18:03:09 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
    Claptrap claptrap = Claptrap("Claptrap");
    Claptrap ennemi = Claptrap("Ennemi");
    
    claptrap.showlifepoints();
    claptrap.attack("Zombie");
    ennemi.attack("Claptrap");
    claptrap.takeDamage(0);
    claptrap.beRepaired(3);
    claptrap.showlifepoints();
    return (0);
}