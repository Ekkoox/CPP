#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class ClapTrap {
    protected:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _energy_points;
        unsigned int _attack_damage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showLifePoints();
        void showEnergyPoints();
        unsigned int getEnergyPoints() const;
        unsigned int getHitPoints() const;
        unsigned int getAttackDamage() const;
        std::string getName() const;
        void setTemporaryBoost(int attackBoost, int energyBoost);
    } ;

#endif