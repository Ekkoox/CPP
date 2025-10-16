#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &rhs);
        virtual ~Animal();

        std::string getType() const;
        void setType(const std::string &type);
        virtual void makeSound() const = 0;
};

#endif