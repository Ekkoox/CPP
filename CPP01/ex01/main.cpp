/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:23:09 by enschnei          #+#    #+#             */
/*   Updated: 2025/07/30 21:18:56 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Error arguments" << std::endl, 1);
    int n = atoi(av[1]);
    if (!n)
        return (std::cout << "Error atoi" << std::endl, 1);
    Zombie *horde = zombieHorde(n, "Zombie");
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}