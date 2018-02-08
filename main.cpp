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

    // читаем словарь из файла
    // сразу игнорируем слова неправильной длины
    const auto dictionary = readDictionaryFrom(dictionaryFileName, size);

    // строим граф из словаря
    // вершины - слова
    // ребрами соединены только те слова, которые различаются ровно на 1 букву
    const auto graph = toGraph(dictionary);

    // находим путь в графе с помощью алгоритма "обход в ширину"
    auto path = graph.findPath(findIn(dictionary, start),
                               findIn(dictionary, finish));
    print(path, dictionary);

    return 0;
}

