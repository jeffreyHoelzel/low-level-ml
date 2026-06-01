#include <cassert>

#include <llml/linalg/matrix.hpp>

int main() {
    const llml::linalg::Matrix matrix{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};

    assert(matrix.rows() == 2);
    assert(matrix.cols() == 3);
    assert(matrix.size() == 6);
    assert(!matrix.empty());

    assert(matrix(0, 0) == 1.0);
    assert(matrix(0, 2) == 3.0);
    assert(matrix(1, 0) == 4.0);
    assert(matrix(1, 2) == 6.0);

    const llml::linalg::Matrix a{{1.0, 2.0}, {3.0, 4.0}};

    const llml::linalg::Matrix b{{5.0, 6.0}, {7.0, 8.0}};

    const auto result = a * b;

    assert(result(0, 0) == 19.0);
    assert(result(0, 1) == 22.0);
    assert(result(1, 0) == 43.0);
    assert(result(1, 1) == 50.0);

    return 0;
}
