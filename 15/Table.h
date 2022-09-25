#ifndef TABLE_H
#define TABLE_H

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Person.h"

class Table {
    public:
        virtual void draw(std::vector<Person*> persons);
    private:
        virtual std::string border(int first, int last, int date, int age);
};

#endif