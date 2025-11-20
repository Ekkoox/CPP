/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:18:42 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/20 18:49:04 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(std::string name) : _name(name)
{
    return ;
}

Data::Data(const Data &src)
{
    (void)src;
    return ;
}

Data::~Data()
{
    return ;
}

Data &Data::operator=(const Data &rhs)
{
    (void)rhs;
    return (*this);
}

Data Data::getName() const
{
    return (*this);
}