/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:40:13 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/11 14:53:09 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    PhoneBook _phonebook;
    std::string command;
    
    std::cout << ("Welcome to the Phonebook!\n") << std::endl;
    while (1)
    {
        std::cout << ("Enter a command (ADD, SEARCH or EXIT): ");
        std::getline(std::cin, command);
        if (command == "ADD")
            _phonebook.addContact();
        else if (command == "SEARCH")
            _phonebook.searchContact();
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
    return (0);
}