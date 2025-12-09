/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:01:01 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/08 16:18:26 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"

int main()
{
{
    Data data("Test Data");

    std::cout << "----- Serialization / Deserialization Test -----" << std::endl;
    uintptr_t raw;
    std::cout << "Original value: " << &data << std::endl;
    raw = Serialization::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Raw adress: " << &raw << std::endl;
    Data *deserialized_ptr = Serialization::deserialize(raw);
    if (deserialized_ptr == &data)
    {
        std::cout << "Deserialized value: " << Serialization::deserialize(raw) << std::endl;
        std::cout << "Verification OK: Les pointeurs sont égaux." << std::endl;
    }
    else
    {
        std::cout << "Deserialized value: " << Serialization::deserialize(raw) << std::endl;
        std::cout << "Verification FAILED: Problème de sérialisation/désérialisation." << std::endl;
    }
}
    
    Data data("Test fail Data");
    
    std::cout << "----- Failed Deserialization Test -----" << std::endl;
        uintptr_t raw;
    std::cout << "Original value: " << &data << std::endl;
    raw = Serialization::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Raw adress: " << &raw << std::endl;
    Data *deserialized_ptr = Serialization::deserialize(raw + 1); // Intentionally corrupting the raw value
    if (deserialized_ptr == &data)
    {
        std::cout << "Deserialized value: " << Serialization::deserialize(raw + 1) << std::endl;
        std::cout << "Verification OK: Les pointeurs sont égaux." << std::endl;
    }
    else
    {
        std::cout << "Deserialized value: " << Serialization::deserialize(raw + 1) << std::endl;
        std::cout << "Verification FAILED: Problème de sérialisation/désérialisation." << std::endl;
    }
    return (0);
}
