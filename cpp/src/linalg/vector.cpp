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
        result[i] = (*this)[i] * scalar;
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

} // namespace llml::linalg
