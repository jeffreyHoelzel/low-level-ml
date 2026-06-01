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

    return 0;
}
