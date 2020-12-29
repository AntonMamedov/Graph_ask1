#pragma once
#include "IGraph.h"


class ListGraph final : public IGraph{
private:
    std::vector<std::vector<int>> adjacencyListArr;
public:
    explicit ListGraph(size_t vCount);
    explicit ListGraph(const IGraph& other);
    ~ListGraph() override = default;
    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;
};
