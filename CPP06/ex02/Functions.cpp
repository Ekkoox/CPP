/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:22:31 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/24 17:26:53 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base*   generate(void)
{
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;
    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    else
        return (new C());
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::bad_cast&) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::bad_cast&) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::bad_cast&) {}

    std::cout << "Unknown Type" << std::endl;
}