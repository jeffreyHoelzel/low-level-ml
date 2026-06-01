#pragma once

#include <stdexcept>
#include <string>

namespace llml::linalg {

class DimensionError : public std::runtime_error {
  public:
    explicit DimensionError(const std::string &message) : std::runtime_error{message} {}
};

class IndexError : public std::out_of_range {
  public:
    explicit IndexError(const std::string &message) : std::out_of_range{message} {}
};

} // namespace llml::linalg
