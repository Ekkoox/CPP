/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:55:38 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/08 12:46:02 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() 
{
    // --- Test avec un Vector ---
    std::cout << "--- Test avec std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        // Recherche d'une valeur existante
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Trouvé : " << *it << std::endl;

        // Recherche d'une valeur inexistante
        std::cout << "Recherche de 99..." << std::endl;
        it = easyfind(vec, 99); // Cela devrait lancer une exception
        std::cout << "Ceci ne devrait pas s'afficher." << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // --- Test avec une List ---
    std::cout << "--- Test avec std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Trouvé : " << *it << std::endl;
        
        // On peut même modifier la valeur via l'itérateur retourné
        *it = 42;
        std::cout << "Valeur modifiée dans la liste : " << lst.back() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}