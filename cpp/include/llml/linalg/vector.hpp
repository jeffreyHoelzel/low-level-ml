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

  private:
    std::vector<double> data_;
};

} // namespace llml::linalg
