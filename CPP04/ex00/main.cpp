/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:23 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/15 17:59:51 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "----- WRONG ANIMAL TESTS -----" << std::endl;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    // const WrongAnimal *test = new cat(); // Ne compile pas, car on ne peut pas convertir un Cat en WrongAnimal
    // const Animal *test = new WrongCat();
    wrongCat->makeSound(); // will output the cat sound!
    wrongMeta->makeSound();
    delete wrongMeta;
    delete wrongCat;
    return (0);
}