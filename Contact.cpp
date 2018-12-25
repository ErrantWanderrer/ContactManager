#include <string>
#include <fstream>
#include <iostream>

#include "Contact.h"

enum Groups {
    NO_GROUP,
    FAMILY,
    FRIENDS,
    COLLEAGUES
} group;

Contact::Contact(std::string name, std::string phone, int group)
{
    setData(name, phone, group);
}

// Здесь задаются данные
void Contact::setData(std::string name, std::string phone, int group)
{
    m_name = name;
    m_phone = phone;
    m_group = group;
}
//get функции для возврата строк с данными

std::string Contact::getName() { 
    return m_name; 
}

std::string Contact::getPhone() { 
    return m_phone; 
}

std::string Contact::getGroup()  { 
    switch(m_group){
        case NO_GROUP:
            return "NO_GROUP";
        case FAMILY:
            return "FAMILY";
        case FRIENDS:
            return "FRIENDS";
        case COLLEAGUES:
            return "COLLEAGUES";
        default:
            return "ERROR";      
    }
}

/*void Contact::add(){
     std::string name;
                std::string phone;
                int group;
                std::cout << "Enter name:\n";
                std::cin >> name;
                std::cout << "Enter phone:\n";
                std::cin >> phone;
                std::cout << "Enter group:\n1 NO_GROUP\n2 FAMILY\n3 FRIENDS\n4 COLLEAGUES\n";
                std::cin >> group;
                
                contact.push_back(Contact(name, phone, group));
}
/*
void Contact::print() {
}
void Contact::edit() {
}
void Contact::delete() {
}
void Contact::save() {
}
void Contact::load() {
}
*/



std::ofstream& operator <<(std::ofstream &os, const Contact &contact) {
    os << "~" << contact.m_name << " " << contact.m_phone << " " << contact.m_group << "\n";
    return os;
}

/*std::istream& operator >>(std::istream &is, Contact &contact){
    is >> contact.m_name >> contact.m_phone >> contact.m_group;
    return is; 
}*/
