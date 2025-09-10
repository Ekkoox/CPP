/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:24:16 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/10 16:07:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//setters

void Contact::setFirstName(const std::string &name) {
    _firstname = name;
}

void Contact::setLastName(const std::string &name) {
    _lastname = name;
}

void Contact::setNickname(const std::string &name) {
    _nickname = name;
}

void Contact::setPhoneNumber(const std::string &number) {
    phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string &secret) {
    _darkestsecret = secret;
}

//getters

std::string Contact::getFirstName() const {
    return _firstname;
}

std::string Contact::getLastName() const {
    return _lastname;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestsecret;
}
