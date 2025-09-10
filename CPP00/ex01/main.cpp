/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:40:13 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/10 18:11:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int main()
{
    std::cout << ("Welcome to the Phonebook!\n") << std::endl;
    while(1)
    {
        std::cout << ("Enter a command (ADD, SEARCH or EXIT): ");
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << ("Exiting the Phonebook. Goodbye!") << std::endl;
            break;
        }
        else if (std::cin.eof())
        {
            std::cout << ("\nExiting the Phonebook. Goodbye!") << std::endl;
            break;
        }
        else
            std::cout << ("Invalid command. Please try again.") << std::endl;
        
    }
    return (EXIT_SUCCESS);
}