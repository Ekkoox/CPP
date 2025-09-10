#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>


class Contact{
    private: 
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestsecret;
    public:
        Contact() {}
        ~Contact() {}
        void setFirstName(const std::string &name);
        void setLastName(const std::string &name);
        void setNickname(const std::string &name);
        void setPhoneNumber(const std::string &number);
        void setDarkestSecret(const std::string &secret);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
        
};

#endif
