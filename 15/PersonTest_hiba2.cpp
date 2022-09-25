#include "MockPerson.h"
#include "Table.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Return;

TEST(PersonTest, getFirstName) {
    MockPerson* andras = new MockPerson("Andras", "Arato", 1921, 3, 9);
    std::vector<Person*> persons = { andras };
    Table t;
    EXPECT_CALL(*andras, getFirstName())
        .Times(2)
        .WillRepeatedly(Return("Andras"));
    EXPECT_CALL(*andras, getLastName())
        .Times(2)
        .WillRepeatedly(Return("Arato"));
    EXPECT_CALL(*andras, getAscBirth())
        .Times(2)
        .WillRepeatedly(Return("9/3/1921"));
    EXPECT_CALL(*andras, getAge())
        .Times(3)
        .WillRepeatedly(Return(-1234));
    EXPECT_EQ(101, andras->getAge());
    t.draw(persons);
    delete andras;
}