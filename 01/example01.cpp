#include<vector>
#include"matrix01.h"

int main() {
  std::vector<std::vector<double>> v1 = {
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34}
  };
  
  std::vector<std::vector<double>> v2;
  v2.resize(4, std::vector<double>(3, 1.));
  
  szeMatrix::Matrix<double> m1(v1);
  szeMatrix::Matrix<double> m2(v2);
  szeMatrix::Matrix<double> multiplied = m1.mul(m2);
  multiplied.print();
  
  return 0;
}
