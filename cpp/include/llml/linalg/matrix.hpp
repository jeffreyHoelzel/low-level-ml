#pragma once

#include <cstddef>
#include <initializer_list>
#include <vector>

namespace llml::linalg {

class Matrix {
  public:
    Matrix();
    Matrix(std::size_t rows, std::size_t cols);
    Matrix(std::size_t rows, std::size_t cols, double value);
    Matrix(std::initializer_list<std::initializer_list<double>> values);

    std::size_t rows() const;
    std::size_t cols() const;
    std::size_t size() const;
    bool empty() const;

    double &operator()(std::size_t row, std::size_t col);
    double operator()(std::size_t row, std::size_t col) const;

  private:
    std::size_t rows_{0};
    std::size_t cols_{0};
    std::vector<double> data_;

    std::size_t index(std::size_t row, std::size_t col) const;
};

} // namespace llml::linalg
