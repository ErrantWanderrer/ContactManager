#ifndef __CONTACT__
#define __CONTACT__

#include <vector>

class Contact {
    public:
        std::string m_name;
        std::string m_phone;
        int m_group;
        Contact(std::string name, std::string phone, int group);
        void setData(std::string name, std::string phone, int group);

        std::string getName();
        std::string getPhone();
        std::string getGroup();   

        friend std::ofstream& operator <<(std::ofstream &os, const Contact &contact);
        //friend std::istream& operator >>(std::istream &is, Contact &contact);
    private:
        
        
};

#endif
