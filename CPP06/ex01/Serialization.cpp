/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:01:23 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/05 12:53:28 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
    return ;
}

Serialization::Serialization(const Serialization &src)
{
    (void)src;
    return ;
}

Serialization::~Serialization()
{
    return ;
}

Serialization &Serialization::operator=(const Serialization &rhs)
{
    (void)rhs;
    return (*this);
}

uintptr_t Serialization::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}