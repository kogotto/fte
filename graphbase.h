#ifndef GRAPHBASE
#define GRAPHBASE

#include <queue>
#include <vector>

#include "matrix.h"

// Структура данных - неориентированный граф
// Количество вершин задается в конструкторе, изменить нельзя
// Вершины нумеруются с 0 до size() - 1
// Ребра задаются функцией setEdge(left, right), где left, right - номера вершин
// findPath - совершает обход графа в ширину и возвращает ветор номеров вершин(путь start-finish)

class GraphBase {
public:
    using Path = std::vector<size_t>;

    GraphBase(size_t vertexCount):
        matrix_(vertexCount)
    {}

    size_t size() const {
        return matrix_.size();
    }

    void setEdge(size_t left, size_t right) {
        matrix_.elem(left, right) = 1;
        matrix_.elem(right, left) = 1;
    }

    bool hasEdge(size_t left, size_t right) {
        return matrix_.elem(left, right) != 0;
    }

    Path findPath(size_t start, size_t finish) const {
        if (start == finish) {
            return Path(1, start);
        }

        const auto localSize = static_cast<int>(size());

        std::queue<int> queue;
        queue.push(finish);

        const int emptySign = -1;
        const int startSign = localSize;
        std::vector<int> visited(localSize, emptySign);
        visited[finish] = startSign;

        while (!queue.empty()) {
            const auto current = queue.front();
            queue.pop();
            for (int i = 0; i < localSize; ++i) {
                if (visited[i] >= 0) {
                    continue;
                }
                if (matrix_.elem(current, i) != 0) {
                    queue.push(i);
                    visited[i] = current;
                }
            }
        }

        Path result;
        for (int i = start; i != startSign; i = visited[i]) {
            result.push_back(i);
        }
        return result;
    }

private:
    Matrix matrix_;
};

#endif // GRAPHBASE

