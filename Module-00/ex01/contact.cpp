#include "main.hpp"

void Contact::setFirstName(std::string str) {
    this->first_name = str;
}

void Contact::setLastName(std::string str) {
    this->last_name = str;
}

void Contact::setPhoneNumber(std::string str) {
    this->phone_number = str;
}

const std::string& Contact::getFirstName(void) const {
    return this->first_name;
}

const std::string& Contact::getLastName(void) const {
    return this->last_name;
}

const std::string& Contact::getPhoneNumber(void) const {
    return this->phone_number;
}
