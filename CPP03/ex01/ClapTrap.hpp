#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class Claptrap {
    private:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _energy_points;
        unsigned int _attack_damage;

    public:
        Claptrap(std::string name);
        ~Claptrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showlifepoints();
} ;

#endif