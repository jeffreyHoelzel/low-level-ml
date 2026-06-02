#pragma once

#include <cstddef>
#include <initializer_list>
#include <vector>

namespace llml::linalg {

class Vector {
  public:
    Vector();
    explicit Vector(std::size_t size);
    Vector(std::size_t size, double value);
    Vector(std::initializer_list<double> values);

    std::size_t size() const;
    bool empty() const;

    double &operator[](std::size_t index);
    double operator[](std::size_t index) const;

    double &at(std::size_t index);
    double at(std::size_t index) const;

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector operator*(double scalar) const;
    Vector operator/(double scalar) const;

    Vector hadamard(const Vector &other) const;

    double dot(const Vector &other) const;

    double sum() const;
    double mean() const;
    double min() const;
    double max() const;

    double norm_l1() const;
    double norm_l2() const;
    double norm_inf() const;

    Vector normalized() const;

  private:
    std::vector<double> data_;
};

Vector operator*(double scalar, const Vector &vector);

} // namespace llml::linalg
