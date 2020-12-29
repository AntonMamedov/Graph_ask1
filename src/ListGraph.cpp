#include "ListGraph.h"

ListGraph::ListGraph(size_t vCount) : adjacencyListArr(vCount)
{
}

ListGraph::ListGraph(const IGraph &other) : adjacencyListArr(other.VerticesCount()){
    for (size_t i = 0; i < adjacencyListArr.size(); i++)
        adjacencyListArr[i] = other.GetNextVertices(i);
}

void ListGraph::AddEdge(int from, int to) {
    adjacencyListArr[from].emplace_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacencyListArr.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjacencyListArr[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (size_t i = 0; i < adjacencyListArr.size(); i++){
        for (auto it = adjacencyListArr[i].begin(); it != adjacencyListArr[i].end(); it++){
            if (*it == vertex)
                prevVertices.emplace_back(i);
        }
    }
    return prevVertices;
}
