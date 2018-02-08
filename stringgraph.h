#ifndef STRINGGRAPH
#define STRINGGRAPH

#include <string>
#include <cassert>

inline bool onlyOneMiss(const std::string & lhs, const std::string & rhs) {
    const auto size = lhs.size();
    assert(size == rhs.size());

    int mismatches = 0;
    for (size_t i = 0; i < size; ++i) {
        if (lhs[i] != rhs[i]) {
            ++mismatches;
        }
    }
    return mismatches == 1;
}

#endif // STRINGGRAPH

