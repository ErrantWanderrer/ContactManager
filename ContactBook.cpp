#include <iostream>
#include <vector>
#include <fstream>

#include "ContactBook.h"
#include "Contact.h"

void ContactBook::addContact() {
    //ContactBook m_contact;
    std::string name;
    std::string phone;
    int group;

    std::cout << "Enter name:\n";
    std::cin >> name;
    std::cout << "Enter phone:\n";
    std::cin >> phone;
    std::cout << "Enter group:\n1 NO_GROUP\n2 FAMILY\n3 FRIENDS\n4 COLLEAGUES\n";
    std::cin >> group;
                
    m_contact.push_back(Contact(name, phone, group));
}

void ContactBook::printContacts() {
    for(int i = 0; i < m_contact.size(); i++) {
        std::cout << i << ": " << m_contact[i].getName() << " " << m_contact[i].getPhone() 
            << " " << m_contact[i].getGroup() << std::endl;
    }
}

void ContactBook::editContact() {
    int element = chooseContact();
    if (element >= 0) {
        std::string name;
        std::string phone;
        int group;

        std::cout << "Enter name:\n";
        std::cin >> name;
        std::cout << "Enter phone:\n";
        std::cin >> phone;
        std::cout << "Enter group:\n1 NO_GROUP\n2 FAMILY\n3 FRIENDS\n4 COLLEAGUES\n";
        std::cin >> group;
                
        m_contact[element] = Contact(name, phone, group);
     } 
     else {
         std::cout << "ERROR" << std::endl;
         return;
     }
}

void ContactBook::deleteContact() {
    int element = chooseContact();
    if(element >= 0) {
        m_contact.erase(m_contact.begin()+element);
    }
    else {
        std::cout << "ERROR" << std::endl;
        return;
    }
}

void ContactBook::saveContacts() {
     std::string name;

    std::cout << "Enter name of file: ";
    std::cin >> name;

    saveToFile(name);
}

void ContactBook::loadContacts() {
    std::string name;

    std::cout << "Enter name of file: ";
    std::cin >> name;

    loadFromFile(name);
}

int ContactBook::chooseContact() {
    std::cout << "Enter number of contct" << std::endl;
    printContacts();
    
    int element = 0;
    std::cin >> element;
    if(element > m_contact.size()) {
        return -1;
    }
    else {
        return element;
    }

}

void ContactBook::saveToFile(std::string name) {
    std::ofstream ofs(name);
    for(int i = 0; i < m_contact.size(); i++) {
        ofs << m_contact[i];
    }
}

void ContactBook::loadFromFile(std::string name) {
    saveToFile("swap");
    m_contact.clear();
    std::ifstream ifs(name);
    int switcher = 0;
    std::string nameFromFile;
    std::string phoneFromFile;
    char group;
    char a;
    for(int i = 0; !ifs.eof(); i++) {
        ifs.get(a);

        if(switcher == 0) {
            if(a == ' ') {
                 switcher++;
            }

            else if(a == '~'){}

            else {
                nameFromFile.push_back(a);
            }
        }

        else if(switcher == 1) {
            if(a == ' ') {
                switcher++;
            }

            else if(a == '~'){}

            else {     
                phoneFromFile.push_back(a);
            }
        }

        else if(switcher == 2) {
            if(a == '\n') {
                switcher++;
            } else {
                group = a;
            }
        }

        else if(switcher == 3) {
            m_contact.push_back(Contact(nameFromFile, phoneFromFile, group-48));

            switcher = 0;
            group = 0;
            nameFromFile.clear();
            phoneFromFile.clear();
        }
    }   
}
