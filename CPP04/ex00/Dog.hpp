#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    private:

    public:
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &rhs);
        virtual ~Dog();
        
        virtual void makeSound() const;
};

#endif