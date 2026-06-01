#include <llml/linalg/exceptions.hpp>
#include <llml/linalg/matrix.hpp>

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

} // namespace llml::linalg