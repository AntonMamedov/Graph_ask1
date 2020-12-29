#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t vCount) : adjacencyMatrix(vCount, std::vector<int>(vCount, 0))
{
}

MatrixGraph::MatrixGraph(const IGraph &other) : adjacencyMatrix(other.VerticesCount()){
    for (size_t i = 0; i < adjacencyMatrix.size(); i++){
        auto nextVertices = other.GetNextVertices(i);
        for (int nextVertex : nextVertices)
            adjacencyMatrix[i][nextVertex] = 1;
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    adjacencyMatrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (size_t i = 0; i < adjacencyMatrix.size(); i++){
        if (adjacencyMatrix[vertex][i])
            nextVertices.emplace_back(i);
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (size_t i = 0; i < adjacencyMatrix.size(); i++){
        if (adjacencyMatrix[i][vertex])
            prevVertices.emplace_back(i);
    }
    return prevVertices;
}