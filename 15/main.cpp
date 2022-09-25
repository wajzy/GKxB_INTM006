#include "Person.h"
#include "Table.h"
#include <vector>

int main() {
    std::vector<Person*> persons = {
        new Person("Andras", "Arato", 1921, 3, 9),
        new Person("Bela", "Bokor", 1978, 12, 2),
        new Person("Cecilia", "Cudar", 2013, 5, 21)
    };
    Table t;
    t.draw(persons);
    for(auto p : persons) {
        delete p;
    }
    return 0;
}