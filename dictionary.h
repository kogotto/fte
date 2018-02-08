#ifndef DICTIONARY
#define DICTIONARY

#include <vector>
#include <string>
#include <algorithm>

using Dictionary = std::vector<std::string>;

inline size_t findIn(const Dictionary & dictionary, const std::string & str) {
    return std::find(dictionary.begin(),
                     dictionary.end(),
                     str) - dictionary.begin();
}

#endif // DICTIONARY

