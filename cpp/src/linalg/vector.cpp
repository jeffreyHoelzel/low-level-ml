#include <algorithm>
#include <cmath>
#include <stdexcept>

#include <llml/linalg/exceptions.hpp>
#include <llml/linalg/vector.hpp>

namespace llml::linalg {

Vector::Vector() = default;

Vector::Vector(const std::size_t size) : data_(size, 0.0) {}

Vector::Vector(const std::size_t size, const double value) : data_(size, value) {}

Vector::Vector(const std::initializer_list<double> values) : data_(values) {}

std::size_t Vector::size() const {
    return data_.size();
}

bool Vector::empty() const {
    return data_.empty();
}

double &Vector::operator[](const std::size_t index) {
    if (index >= data_.size()) {
        throw IndexError{"Vector index out of bounds"};
    }
    return data_[index];
}

double Vector::operator[](const std::size_t index) const {
    if (index >= data_.size()) {
        throw IndexError{"Vector index out of bounds"};
    }
    return data_[index];
}

double &Vector::at(const std::size_t index) {
    return (*this)[index];
}

double Vector::at(const std::size_t index) const {
    return (*this)[index];
}

Vector Vector::operator+(const Vector &other) const {
    if (size() != other.size()) {
        throw DimensionError{"Vector sizes must match for addition"};
    }
    Vector result(size());
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

Vector Vector::operator-(const Vector &other) const {
    if (size() != other.size()) {
        throw DimensionError{"Vector sizes must match for subtraction"};
    }
    Vector result(size());
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}

Vector Vector::operator*(double scalar) const {
    Vector result(size());
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result[i] = (*this)[i] * scalar;
    }
    return result;
}

Vector Vector::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero not allowed");
    }
    Vector result(size());
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result[i] = (*this)[i] / scalar;
    }
    return result;
}

Vector Vector::hadamard(const Vector &other) const {
    if (size() != other.size()) {
        throw DimensionError{"Vector sizes must match for Hadamard product"};
    }

    Vector result(size());
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result[i] = (*this)[i] * other[i];
    }

    return result;
}

double Vector::dot(const Vector &other) const {
    if (size() != other.size()) {
        throw DimensionError{"Vector sizes must match for dot product"};
    }
    double result(0.0);
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result += (*this)[i] * other[i];
    }
    return result;
}

double Vector::sum() const {
    double result{0.0};
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result += (*this)[i];
    }
    return result;
}

double Vector::mean() const {
    if (empty()) {
        throw std::invalid_argument("Cannot calculate mean of empty vector");
    }
    return sum() / static_cast<double>(size());
}

double Vector::min() const {
    if (empty()) {
        throw std::invalid_argument("Cannot calculate minimum of empty vector");
    }

    double result{(*this)[0]};
    std::size_t i;
    for (i = 1; i < size(); ++i) {
        if ((*this)[i] < result) {
            result = (*this)[i];
        }
    }
    return result;
}

double Vector::max() const {
    if (empty()) {
        throw std::invalid_argument("Cannot calculate minimum of empty vector");
    }

    double result{(*this)[0]};
    std::size_t i;
    for (i = 1; i < size(); ++i) {
        if ((*this)[i] > result) {
            result = (*this)[i];
        }
    }
    return result;
}

double Vector::norm_l1() const {
    double result{0.0};
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result += std::abs((*this)[i]);
    }
    return result;
}

double Vector::norm_l2() const {
    double result{0.0};
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        result += (*this)[i] * (*this)[i];
    }
    return std::sqrt(result);
}

double Vector::norm_inf() const {
    double result{0.0};
    std::size_t i;
    for (i = 0; i < size(); ++i) {
        const double value = std::abs((*this)[i]);
        if (value > result) {
            result = value;
        }
    }
    return result;
}

Vector Vector::normalized() const {
    const double norm = norm_l2();
    if (norm == 0.0) {
        throw std::invalid_argument("Cannot normalize zero vector");
    }
    return (*this) / norm;
}

Vector operator*(const double scalar, const Vector &vector) {
    return vector * scalar;
}

} // namespace llml::linalg
