#include"matrix05.h"
#include<vector>
#include<cmath>
#include<gtest/gtest.h>

TEST(MulTest, meaningful) {
  std::vector<std::vector<int>> left = {
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34}
  };
  std::vector<std::vector<int>> right;
  right.resize(4, std::vector<int>(3, 1.));
  std::vector<std::vector<int>> expected = {
    {50, 50, 50},
    {90, 90, 90},
    {130, 130, 130}
  };
  szeMatrix::Matrix<int> m1(left);
  szeMatrix::Matrix<int> m2(right);
  szeMatrix::Matrix<int> multiplied = m1.mul(m2);
  ASSERT_EQ(expected.size(), multiplied.getRowCount());
  ASSERT_EQ(expected[0].size(), multiplied.getColCount());
  for(unsigned row=0; row<expected.size(); row++) {
    for(unsigned col=0; col<expected[row].size(); col++) {
      EXPECT_EQ(expected[row][col], multiplied.get(row, col));
    }
  }
}

TEST(MulTest, rounding) {
  std::vector<std::vector<double>> left = {
    {sqrt(2.), 0.},
    {0., 1./3.}
  };
  std::vector<std::vector<double>> right;
  right.resize(2, std::vector<double>(2, 1.));
  std::vector<std::vector<double>> expected = {
    {1.414213562, 1.414213562},
    {0.333333333, 0.333333333}
  };
  szeMatrix::Matrix<double> m1(left);
  szeMatrix::Matrix<double> m2(right);
  szeMatrix::Matrix<double> multiplied = m1.mul(m2);
  ASSERT_EQ(expected.size(), multiplied.getRowCount());
  ASSERT_EQ(expected[0].size(), multiplied.getColCount());
  for(unsigned row=0; row<expected.size(); row++) {
    for(unsigned col=0; col<expected[row].size(); col++) {
      //EXPECT_EQ(expected[row][col], multiplied.get(row, col));
      EXPECT_DOUBLE_EQ(expected[row][col], multiplied.get(row, col));
    }
  }
}
