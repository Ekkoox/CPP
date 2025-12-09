/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:51:01 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/08 16:27:30 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

int main() 
{
    Base* p = generate();

    std::cout << "identify(*p): ";
    identify(*p);

    std::cout << "identify(p): ";
    identify(p);

    delete (p);

    Base *p2 = generateD();
    std::cout << "identify(*p2): ";
    identify(*p2);
    std::cout << "identify(p2): ";
    identify(p2);

    delete (p2);

    return (0);
}