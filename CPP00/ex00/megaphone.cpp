/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:09:34 by enschnei            #+#    #+#           */
/*   Updated: 2025/07/21 15:09:34 by enschnei           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for(int i = 1; i < ac ; i++)
    {
        for(int j = 0; av[i][j]; j++)
        {
            std::cout << (char)std::toupper(av[i][j]);
        }
    }
    std::cout << std::endl;
    return (0);
}