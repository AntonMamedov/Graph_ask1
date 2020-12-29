#include "SetGraph.h"

SetGraph::SetGraph(size_t vCount) : adjacencySetArr(vCount)
{
}

SetGraph::SetGraph(const IGraph &other) : adjacencySetArr(other.VerticesCount()){
    for (size_t i = 0; i < adjacencySetArr.size(); i++){
        auto nextVertices = other.GetNextVertices(i);
        for (int nextVertex : nextVertices)
            adjacencySetArr[i].emplace(nextVertex);
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjacencySetArr[from].emplace(to);
}

int SetGraph::VerticesCount() const {
    return adjacencySetArr.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    auto& nextVertices = adjacencySetArr[vertex];
    std::vector<int> resultNexVertices;
    resultNexVertices.reserve(nextVertices.size());
    for (int nextVertex : nextVertices){
        resultNexVertices.emplace_back(nextVertex);
    }
    return resultNexVertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (size_t i = 0; i < adjacencySetArr.size(); i++){
        auto requiredVertex = adjacencySetArr[i].find(vertex);
        if  (requiredVertex != adjacencySetArr[i].end())
            prevVertices.emplace_back(i);
    }
    return prevVertices;
}
