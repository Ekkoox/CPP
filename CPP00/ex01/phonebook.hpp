#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <string>

class PhoneBook {
    private:
        Contact contacts[8];   // Tableau fixe de 8 contacts
        int contactCount;      // Nombre total de contacts ajoutés
        int oldestIndex;       // Pour savoir quel contact remplacer si plein

    public:
        PhoneBook();           // Constructeur
        ~PhoneBook();          // Destructeur
        void addContact();     // Ajouter un contact
        void searchContact();  // Afficher et chercher un contact
};

#endif
