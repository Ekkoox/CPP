/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:44:34 by enschnei          #+#    #+#             */
/*   Updated: 2025/07/31 18:20:11 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        // horde[i] = new Zombie(name);
        horde[i].setName(name);
    return (horde);
}
