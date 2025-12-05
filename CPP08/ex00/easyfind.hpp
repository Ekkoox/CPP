#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <exception>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return ("Element not found in container");
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    // std::find retourne un itérateur sur l'élément trouvé
    // ou container.end() si rien n'est trouvé.
    if (it == container.end()) {
        // Si l'itérateur a atteint la fin, l'élément n'est pas là.
        throw NotFoundException();
        // Alternativement, on pourrait lancer : throw std::runtime_error("Not found");
    }
    return (it);
}

#endif