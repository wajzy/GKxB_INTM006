#include"matrix10.h"
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

TEST(MulTest, equality) {
  std::vector<std::vector<double>> left = {
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34}
  };
  std::vector<std::vector<double>> right;
  right.resize(4, std::vector<double>(3, 1.));
  std::vector<std::vector<double>> expected = {
    {50, 50, 50},
    {90, 90, 90},
    {130, 130, 130}
  };
  szeMatrix::Matrix<double> m1(left);
  szeMatrix::Matrix<double> m2(right);
  szeMatrix::Matrix<double> mexp(expected);
  szeMatrix::Matrix<double> multiplied = m1.mul(m2);
  ASSERT_EQ(mexp.getRowCount(), multiplied.getRowCount());
  ASSERT_EQ(mexp.getColCount(), multiplied.getColCount());
  ASSERT_EQ(mexp, multiplied);
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
      EXPECT_NEAR(expected[row][col], multiplied.get(row, col), 1e-9);
    }
  }
}

TEST(MulTest, print) {
  std::vector<std::vector<double>> right;
  right.resize(2, std::vector<double>(2, 1.));
  szeMatrix::Matrix<double> m2(right);
  const char* expected = "1\t1\t\n1\t1\t\n";
  testing::internal::CaptureStdout();
  m2.print();
  std::string output = testing::internal::GetCapturedStdout();
  //ASSERT_EQ(expected, output.c_str());
  ASSERT_STREQ(expected, output.c_str());
}

TEST(MulTest, toString) {
  std::vector<std::vector<double>> right;
  right.resize(2, std::vector<double>(2, 1.));
  szeMatrix::Matrix<double> m2(right);
  std::string expected = "1\t1\t\n1\t1\t\n";
  ASSERT_EQ(expected, m2.toString());
}

TEST(MulTest, toCString) {
  std::vector<std::vector<double>> right;
  right.resize(2, std::vector<double>(2, 1.));
  szeMatrix::Matrix<double> m2(right);
  const char* expected = "1\t1\t\n1\t1\t\n";
  ASSERT_STREQ(expected, m2.toCString());
}
