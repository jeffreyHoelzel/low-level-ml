#include <cassert>

#include <llml/linalg/vector.hpp>

int main() {
    const llml::linalg::Vector vector{1.0, 2.0, 3.0};

    assert(vector.size() == 3);
    assert(!vector.empty());
    assert(vector[0] == 1.0);
    assert(vector[1] == 2.0);
    assert(vector[2] == 3.0);

    return 0;
}
