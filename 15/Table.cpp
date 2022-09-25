#include "Table.h"

void Table::draw(std::vector<Person*> persons) {
    int firstW=0, lastW=0, dateW=0, ageW=0;
    int length;
    for(auto p : persons) {
        if((length = p->getFirstName().length()) > firstW) {
            firstW = length;
        }
        if((length = p->getLastName().length()) > lastW) {
            lastW = length;
        }
        if((length = p->getAscBirth().length()) > dateW) {
            dateW = length;
        }
        if((length = std::to_string(p->getAge()).length()) > ageW) {
            ageW = length;
        }
    }
    std::cout << border(firstW, lastW, dateW, ageW) << std::endl;
    for(auto p : persons) {
        std::cout << "| " << std::setw(firstW) << p->getFirstName()
                  << " " << std::setw(lastW) << p->getLastName() 
                  << " | " << std::setw(dateW) << p->getAscBirth() 
                  << " | " << std::setw(ageW) << p->getAge() 
                  << " |" << std::endl;
    }
    std::cout << border(firstW, lastW, dateW, ageW) << std::endl;
}

std::string Table::border(int first, int last, int date, int age) {
    std::string s = "+";
    s.append(first + last + 3, '-');
    s += '+';
    s.append(date + 2, '-');
    s += '+';
    s.append(age + 2, '-');
    s += '+';
    return s;
}
