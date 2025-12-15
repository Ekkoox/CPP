/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:05:22 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/15 17:46:07 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
        return (1);
    }
    try {
        BitcoinExchange btcExchange;
        
        btcExchange.loadData("data.csv");
        btcExchange.processInput(av[1]);
    } 
    catch (const std::exception& e) {
        std::cerr << "Error loading data: " << e.what() << std::endl;
        return (1);
    }
    return (0);   
}