#pragma once
#include "IGraph.h"


class MatrixGraph final : public IGraph{
private:
    std::vector<std::vector<int>> adjacencyMatrix;
public:
    explicit MatrixGraph(size_t vCount);
    explicit MatrixGraph(const IGraph& other);
    ~MatrixGraph() override = default;
    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;
};
