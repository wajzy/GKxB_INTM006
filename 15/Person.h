#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <ctime>

class Person {
    public:
        Person(std::string firstName, 
            std::string lastName,
            int year, int month, int date) {
            this->firstName = firstName;
            this->lastName = lastName;
            struct tm birthTM = {0, 0, 0, date, month-1, year-1900, 0, 0, -1};
            this->birth = mktime(&birthTM);
        }
        virtual std::string getFirstName(); 
        virtual std::string getLastName(); 
        virtual time_t getBirth();
        virtual std::string getAscBirth();
        virtual int getAge();
        virtual ~Person() {}
    protected:
        std::string firstName;
        std::string lastName;
        time_t birth;
};

#endif