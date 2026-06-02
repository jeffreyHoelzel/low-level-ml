#pragma once

#include <cstddef>
#include <initializer_list>
#include <vector>

#include <llml/linalg/vector.hpp>

namespace llml::linalg {

class Matrix {
  public:
    Matrix();
    Matrix(std::size_t rows, std::size_t cols);
    Matrix(std::size_t rows, std::size_t cols, double value);
    Matrix(std::initializer_list<std::initializer_list<double>> values);

    static Matrix identity(std::size_t size);
    static Matrix zeros(std::size_t rows, std::size_t cols);
    static Matrix ones(std::size_t rows, std::size_t cols);

    std::size_t rows() const;
    std::size_t cols() const;
    std::size_t size() const;
    bool empty() const;
    bool is_square() const;

    double &operator()(std::size_t row, std::size_t col);
    double operator()(std::size_t row, std::size_t col) const;

    double &at(std::size_t row, std::size_t col);
    double at(std::size_t row, std::size_t col) const;

    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(double scalar) const;
    Matrix operator/(double scalar) const;

    Matrix hadamard(const Matrix &other) const;

    Vector operator*(const Vector &vector) const;
    Matrix operator*(const Matrix &matrix) const;

    Vector row(std::size_t row_index) const;
    Vector col(std::size_t col_index) const;
    Vector diagonal() const;

    double trace() const;

    Matrix transpose() const;

  private:
    std::size_t rows_{0};
    std::size_t cols_{0};
    std::vector<double> data_;

    std::size_t index(std::size_t row, std::size_t col) const;
};

Matrix operator*(double scalar, const Matrix &matrix);

} // namespace llml::linalg
