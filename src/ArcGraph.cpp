#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t vCount) {
    vertexCount = vCount;
}

ArcGraph::ArcGraph(const IGraph &other) {
    vertexCount = other.VerticesCount();
    for (size_t i = 0; i < vertexCount; i++){
        auto nextVertices = other.GetNextVertices(i);
//        for (int nextVertice : nextVertices){
//            std::cout << i << ' ' << nextVertice << std::endl;
//        }
        for (int nextVertex : nextVertices)
            arcArr.emplace_back(i, nextVertex);
    }
}

void ArcGraph::AddEdge(int from, int to) {
    arcArr.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertexCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (const auto & i : arcArr){
        if (i.first == vertex)
            nextVertices.emplace_back(i.second);
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (const auto & i : arcArr){
        if (i.second == vertex)
            prevVertices.emplace_back(i.first);
    }
    return prevVertices;
}
