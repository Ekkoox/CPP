#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>

class Zombie {
    private :
        std::string name;

    public :
        Zombie();
        Zombie (std::string name);
        void announce(void);
        void setName(std::string name);

};

class Zombie2 {
    private :
        std::string name;

    public :
        Zombie2() {}
        Zombie2 (std::string name);
        void announce(void);
        void setName(std::string name);

};

Zombie* zombieHorde(int N, std::string name);

#endif