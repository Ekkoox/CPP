/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:23:09 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/16 15:03:44 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int n = 8; 
    Zombie *horde = zombieHorde(n, "Zombie");
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}