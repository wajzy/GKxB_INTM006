#include<vector>
#include<iostream>
#include<sstream>
#include<chrono>
#include<random>
#include<stdexcept>
namespace szeMatrix {

template<class T>
class Matrix {
  protected:
    std::vector<std::vector<T>> mtx;
  
  public:
    Matrix(int rows, int cols, T min, T max);
    Matrix(std::vector<std::vector<T>> src);
    Matrix<T> mul(Matrix<T> right) const;
    void print() const;
    std::string toString() const;
    const char* toCString() const;
    int getRowCount() const { return mtx.size(); }
    int getColCount() const { return mtx[0].size(); }
    T get(int row, int column) const { return mtx[row][column]; }
    template<class U>
    friend bool operator==(const Matrix<U> &m1, const Matrix<U> &m2);
};

template<class T>
Matrix<T>::Matrix(int rows, int cols, T min, T max) {
  if(rows<0 or cols<0) {
    std::cerr << "Row and column numbers must be non-negative.";
    exit(1);
  }
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 rng(seed);
  std::uniform_int_distribution<uint32_t> dist;
  mtx.resize(rows, std::vector<T>(cols));
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      mtx[r][c] = min+(T)dist(rng)/rng.max()*(max-min);
    }
  }
}

template<class T>
Matrix<T>::Matrix(std::vector<std::vector<T>> src) {
  bool firstRow = true;
  unsigned numCols;
  for(auto row : src) {
    if(firstRow) {
      numCols = row.size();
      firstRow = false;
    } else {
      if(numCols != row.size()) {
        throw std::range_error("Row lengths are different.");
      }
    }
    mtx.push_back(row);
  }
}

template<class T>
void Matrix<T>::print() const {
  for(auto row : mtx) {
    for(auto elem : row) {
      std::cout << elem << '\t';
    }
    std::cout << std::endl;
  }
}

template<class T>
std::string Matrix<T>::toString() const {
  std::stringstream ss;
  for(auto row : mtx) {
    for(auto elem : row) {
      ss << elem << '\t';
    }
    ss << std::endl;
  }
  return ss.str();
}

template<class T>
const char* Matrix<T>::toCString() const {
  return toString().c_str();
}

template<class T>
Matrix<T> Matrix<T>::mul(Matrix<T> right) const {
  // Rows of left matrix and result matrix
  int i = mtx.size();
  // Columns of right matrix and res. matrix
  int j = right.mtx[0].size();
  // Columns of left matrix and rows of right matrix
  int k = right.mtx.size();
  
  // Creating an empty result matrix
  std::vector<std::vector<T>> res; 
  // Resizing and filling it with zeros
  res.resize(i, std::vector<T>(j, 0.)); 
  
  for(int r=0; r<i; r++) { // Matrix multiplication
    for(int c=0; c<j; c++) {
      for(int item=0; item<k; item++) {
        res[r][c] += mtx[r][item]*right.mtx[item][c];
      }
    }
  }
  
  return Matrix(res);
}

template<class U>
bool operator==(const Matrix<U> &m1, const Matrix<U> &m2) { 
  return m1.mtx==m2.mtx;
}

}
