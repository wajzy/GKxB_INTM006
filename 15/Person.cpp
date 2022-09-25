#include "Person.h"

std::string Person::getFirstName() {
    return this->firstName;
}

std::string Person::getLastName() {
    return this->lastName;
}

time_t Person::getBirth() {
    return this->birth;
}

std::string Person::getAscBirth() {
    struct tm *birth = localtime(&this->birth);
    return std::to_string(birth->tm_mday) + "/" + std::to_string(birth->tm_mon+1) + "/" + std::to_string(birth->tm_year+1900);
}

int Person::getAge() {
    struct tm birthTM = *localtime(&birth);
    time_t now = time(nullptr);
    struct tm nowTM = *localtime(&now);
    
    int age = nowTM.tm_year - birthTM.tm_year;
    if(nowTM.tm_mon < birthTM.tm_mon) {
        age--;
    } else if(nowTM.tm_mon==birthTM.tm_mon && nowTM.tm_mday<birthTM.tm_mday) {
        age--;
    }
    return age;
}
