#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:
        bool _guard_mode;
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        void takeDamage(unsigned int amount);
        void guardGate();
        void setGuardMode(bool mode);
        bool getGuardMode() const;
};

#endif 