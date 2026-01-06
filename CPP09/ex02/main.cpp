/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:46:12 by enschnei          #+#    #+#             */
/*   Updated: 2026/01/06 15:30:26 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    // srand(time(0));
    if (ac < 2)
    {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return (1);
    }
    
    PmergeMe algo;
    
    if (algo.parseInput(ac, av) != 0)
        return (EXIT_FAILURE);
    std::cout << "Input parsed successfully." << std::endl;
    algo.sortVector();
    algo.sortDeque();
    algo.printResults();
    return (EXIT_SUCCESS);
}