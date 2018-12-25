#include <iostream>
#include <string>
#include <vector>

#include "ContactBook.h"

std::string helloWord = "Menu:\n1 Add\n2 Print\n3 Edit\n4 Delete\n5 Save\n6 Load\n7 Exit\n";


int main(int argc, char ** argv) {
    ContactBook contactBook;

    bool flag = true;
    char trigger = 0;

    while(flag) {    
        std::cout << helloWord;        
        std::cin >> trigger;

        switch(trigger){
            case '1':
                contactBook.addContact();
                break;
            case '2':
                contactBook.printContacts();
                break;
            case '3':
                contactBook.editContact();
                break;
            case '4':
                contactBook.deleteContact();
                break;
            case '5':
                contactBook.saveContacts();
                break;
            case '6':
                contactBook.loadContacts();
                break;
            case '7':
                flag = false;
                break;       
            default:
                std::cout << "ERROR\n";        
        }
    }
    return 0;
}
