#include"matrix12.h"
#include<vector>
#include<cmath>
#include<gtest/gtest.h>

class MatrixTest : public ::testing::Test {
  protected:
    szeMatrix::Matrix<double>* mtx2by2;
    const char* expectedStr = "1\t1\t\n1\t1\t\n";
    void SetUp() override {
      std::vector<std::vector<double>> vec2by2;
      vec2by2.resize(2, std::vector<double>(2, 1.));
      mtx2by2 = new szeMatrix::Matrix<double>(vec2by2);
    }
    void TearDown() override {
      delete mtx2by2;
    }
};

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

TEST(MulTest, randomized) {
  int rows = 2;
  int cols = 3;
  double min = -3.;
  double max = +3.;
  szeMatrix::Matrix<double> mtxRnd(rows, cols, min, max);
  ASSERT_EQ(rows, mtxRnd.getRowCount());
  ASSERT_EQ(cols, mtxRnd.getColCount());
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      double val = mtxRnd.get(r, c);
      EXPECT_GE(max, val);
      EXPECT_LE(min, val);
    }
  }
}

TEST_F(MatrixTest, print) {
  testing::internal::CaptureStdout();
  mtx2by2->print();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_STREQ(expectedStr, output.c_str());
}

TEST_F(MatrixTest, toString) {
  std::string expected = expectedStr;
  ASSERT_EQ(expected, mtx2by2->toString());
}

TEST_F(MatrixTest, toCString) {
  ASSERT_STREQ(expectedStr, mtx2by2->toCString());
}
