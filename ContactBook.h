#ifndef __CONTACT_BOOK__
#define __CONTACT_BOOK__

#include "Contact.h"

class ContactBook {
    public:
        //ContactBook();
        void addContact();
        void printContacts();
        void editContact();
        void deleteContact();
        void saveContacts();
        void loadContacts();
    private:
        std::vector <Contact> m_contact;
        int chooseContact();
        void saveToFile(std::string name);
        void loadFromFile(std::string name);
};

#endif
