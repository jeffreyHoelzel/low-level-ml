#include <llml/linalg/exceptions.hpp>
#include <llml/linalg/matrix.hpp>
#include <llml/linalg/vector.hpp>

namespace llml::linalg {

Matrix::Matrix() = default;

Matrix::Matrix(std::size_t rows, std::size_t cols)
    : rows_{rows}, cols_{cols}, data_(rows * cols, 0.0) {}

Matrix::Matrix(std::size_t rows, std::size_t cols, double value)
    : rows_{rows}, cols_{cols}, data_(rows * cols, value) {}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> values)
    : rows_{values.size()}, cols_{values.size() == 0 ? 0 : values.begin()->size()} {
    data_.reserve(rows_ * cols_);

    for (const auto &row : values) {
        if (row.size() != cols_) {
            throw DimensionError{"All matrix rows must have the same number of columns"};
        }
        for (const double value : row) {
            data_.push_back(value);
        }
    }
}

std::size_t Matrix::rows() const {
    return rows_;
}

std::size_t Matrix::cols() const {
    return cols_;
}

std::size_t Matrix::size() const {
    return data_.size();
}

bool Matrix::empty() const {
    return data_.empty();
}

double &Matrix::operator()(std::size_t row, std::size_t col) {
    return data_[index(row, col)];
}

double Matrix::operator()(std::size_t row, std::size_t col) const {
    return data_[index(row, col)];
}

std::size_t Matrix::index(std::size_t row, std::size_t col) const {
    if (row >= rows_ || col >= cols_) {
        throw IndexError{"Matrix index out of bounds"};
    }
    return row * cols_ + col;
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw DimensionError{"Matrix dimensions must watch for addition"};
    }
    Matrix result(rows_, cols_);
    std::size_t row, col;
    for (row = 0; row < rows_; ++row) {
        for (col = 0; col < cols_; ++col) {
            result(row, col) = (*this)(row, col) + other(row, col);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw DimensionError{"Matrix dimensions must watch for subtraction"};
    }
    Matrix result(rows_, cols_);
    std::size_t row, col;
    for (row = 0; row < rows_; ++row) {
        for (col = 0; col < cols_; ++col) {
            result(row, col) = (*this)(row, col) - other(row, col);
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows_, cols_);
    std::size_t row, col;
    for (row = 0; row < rows_; ++row) {
        for (col = 0; col < cols_; ++col) {
            result(row, col) = (*this)(row, col) * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero not allowed");
    }
    Matrix result(rows_, cols_);
    std::size_t row, col;
    for (row = 0; row < rows_; ++row) {
        for (col = 0; col < cols_; ++col) {
            result(row, col) = (*this)(row, col) * scalar;
        }
    }
    return result;
}

Vector Matrix::operator*(const Vector &vector) const {
    if (cols_ != vector.size()) {
        throw DimensionError{"Matrix columns must match vector size"};
    }
    Vector result(rows_);
    std::size_t row, col;
    for (row = 0; row < rows_; ++row) {
        double sum{0.0};
        for (col = 0; col < cols_; ++col) {
            sum += (*this)(row, col) * vector[col];
        }
        result[row] = sum;
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &matrix) const {
    if (cols_ != matrix.rows_) {
        throw DimensionError{"Size of left matrix columns must match size of right matrix rows"};
    }
    Matrix result(rows_, matrix.cols_);
    std::size_t row, col, k;
    for (row = 0; row < rows_; ++row) {
        for (col = 0; col < matrix.cols_; ++col) {
            double sum{0.0};
            for (k = 0; k < cols_; ++k) {
                sum += (*this)(row, k) * matrix(k, col);
            }
            result(row, col) = sum;
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    std::size_t row, col;
    for (row = 0; row < rows_; ++row) {
        for (col = 0; col < cols_; ++col) {
            result(col, row) = (*this)(row, col);
        }
    }
    return result;
}

} // namespace llml::linalg