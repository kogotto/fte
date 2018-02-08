#ifndef DICTIONARY
#define DICTIONARY

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using Dictionary = std::vector<std::string>;

inline size_t findIn(const Dictionary & dictionary, const std::string & str) {
    return std::find(dictionary.begin(),
                     dictionary.end(),
                     str) - dictionary.begin();
}

inline Dictionary readDictionaryFrom(const char * fileName, size_t wordSize) {
    Dictionary result;
    std::ifstream stream(fileName);
    while (stream) {
        std::string str;
        stream >> str;
        if (str.size() == wordSize) {
            result.push_back(move(str));
        }
    }
    return result;
}

#endif // DICTIONARY

