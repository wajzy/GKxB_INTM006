#include "gmock/gmock.h"
#include "Person.h"

class MockPerson : public Person {
    public:
        MockPerson(std::string firstName, 
            std::string lastName,
            int year, int month, int date) : Person(firstName, lastName, year, month, date) {}
        MOCK_METHOD(std::string, getFirstName, (), (override));
        MOCK_METHOD(std::string, getLastName, (), (override));
        MOCK_METHOD(std::string, getAscBirth, (), (override));
        MOCK_METHOD(int, getAge, (), (override));
};