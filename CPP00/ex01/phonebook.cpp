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

#include "phonebook.hpp"

// Constructeur
PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {
}

// Destructeur
PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook destroyed." << std::endl;
}

// Implémentation de addContact
void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    // Ajouter dans le tableau
    if (contactCount < 8) {
        contacts[contactCount] = newContact;
        contactCount++;
    } else {
        // Si plein, on écrase le plus ancien
        contacts[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }

    std::cout << "Contact added successfully!" << std::endl;
}

std::string formatField(const std::string &field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

// Implémentation de searchContact
void PhoneBook::searchContact() {
    if (contactCount == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    // Affichage du tableau
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }

    // Demander un index
    std::string input;
    std::cout << "Enter index to view details: ";
    std::getline(std::cin, input);

    if (input.size() != 1 || !isdigit(input[0])) {
        std::cout << "Invalid index format." << std::endl;
        return;
    }

    int index = input[0] - '0';
    if (index < 0 || index >= contactCount) {
        std::cout << "Invalid index number." << std::endl;
        return;
    }

    // Afficher les détails
    std::cout << "First Name: "    << contacts[index].getFirstName()    << std::endl;
    std::cout << "Last Name: "     << contacts[index].getLastName()     << std::endl;
    std::cout << "Nickname: "      << contacts[index].getNickname()     << std::endl;
    std::cout << "Phone Number: "  << contacts[index].getPhoneNumber()  << std::endl;
    std::cout << "Darkest Secret: "<< contacts[index].getDarkestSecret()<< std::endl;
}
