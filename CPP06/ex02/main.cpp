/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:51:01 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/24 17:29:15 by enschnei         ###   ########.fr       */
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
    return (0);
}