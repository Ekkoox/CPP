#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &rhs);
        virtual ~WrongAnimal();

        std::string getType() const;
        void setType(const std::string &type);
        virtual void makeSound() const;
};

#endif