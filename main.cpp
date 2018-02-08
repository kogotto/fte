#include <cassert>
#include <string>
#include "dictionary.h"
#include "stringgraph.h"

void readInput(const char * inputFileName,
               std::string & start,
               std::string & finish) {
    std::ifstream stream(inputFileName);
    assert(stream.is_open());
    stream >> start;
    stream >> finish;
}

int main(int argc, char *argv[])
{
    assert(argc == 3);

    const char * inputFileName = argv[1];
    const char * dictionaryFileName = argv[2];

    std::string start;
    std::string finish;
    readInput(inputFileName, start, finish);

    const auto size = start.size();
    assert(size == finish.size());

    const auto dictionary = readDictionaryFrom(dictionaryFileName, size);
    const auto graph = toGraph(dictionary);

    auto path = graph.findPath(findIn(dictionary, start),
                               findIn(dictionary, finish));
    print(path, dictionary);

    return 0;
}

