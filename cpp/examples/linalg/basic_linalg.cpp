#include <iostream>

#include <llml/llml.hpp>

int main() {
    const llml::linalg::Matrix matrix{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    std::cout << "Rows: " << matrix.rows() << std::endl;
    std::cout << "Cols: " << matrix.cols() << std::endl;
    std::cout << "Matrix size: " << matrix.size() << std::endl;
    std::cout << "Value at row 1, col 2: " << matrix(1, 2) << std::endl;

    const llml::linalg::Vector vector{11.0, 12.0, 13.0};
    std::cout << "Vector size: " << vector.size() << std::endl;
    std::cout << "Value at index 2: " << vector[2] << std::endl;

    return 0;
}
