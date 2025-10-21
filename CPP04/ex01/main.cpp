/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:23 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/20 15:34:56 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- ANIMAL TESTS -----" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n----- BRAIN DEEP COPY TEST -----" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
    } // ici, tmp est détruit ⇒ on vérifie qu’il ne supprime pas le Brain de basic
    
    std::cout << "\n----- ARRAY OF ANIMALS -----" << std::endl;

    Animal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    std::cout << "\nCleaning up..." << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n----- WRONG ANIMAL TESTS -----" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
