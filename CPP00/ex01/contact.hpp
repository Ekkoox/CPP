#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact{
    private: 
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestsecret;
    public:
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

