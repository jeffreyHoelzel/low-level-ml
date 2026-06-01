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

} // namespace llml::linalg
