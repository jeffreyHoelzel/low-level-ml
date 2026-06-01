#include <cassert>

#include <llml/linalg/vector.hpp>

int main() {
    const llml::linalg::Vector vector{1.0, 2.0, 3.0};

    assert(vector.size() == 3);
    assert(!vector.empty());
    assert(vector[0] == 1.0);
    assert(vector[1] == 2.0);
    assert(vector[2] == 3.0);

    const llml::linalg::Vector a{1.0, 2.0, 3.0};
    const llml::linalg::Vector b{4.0, 5.0, 6.0};

    const auto sum = a + b;
    assert(sum[0] == 5.0);
    assert(sum[1] == 7.0);
    assert(sum[2] == 9.0);

    assert(a.dot(b) == 32.0);

    return 0;
}
