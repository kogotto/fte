#ifndef STRINGGRAPH
#define STRINGGRAPH

#include <string>
#include <iostream>
#include <cassert>

#include "graphbase.h"
#include "dictionary.h"

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

inline GraphBase toGraph(const Dictionary & dictionary) {
    const auto size = dictionary.size();
    GraphBase result(size);

    for (size_t i = 0; i < size - 1; ++i) {
        const auto & left = dictionary[i];
        for (size_t j = i + 1; j < size; ++j) {
            const auto & right = dictionary[j];
            if (onlyOneMiss(left, right)) {
                result.setEdge(i, j);
            }
        }
    }

    return result;
}

void print(const GraphBase::Path & path,
           const Dictionary & dictionary) {
    for (const auto & i: path) {
        std::cout << dictionary[i] << '\n';
    }
}

#endif // STRINGGRAPH

