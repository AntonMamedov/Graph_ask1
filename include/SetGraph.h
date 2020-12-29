#pragma once
#include <set>

#include "IGraph.h"

class SetGraph final : public IGraph{
private:
    std::vector<std::set<int>> adjacencySetArr;
public:
    explicit SetGraph(size_t vCount);
    explicit SetGraph(const IGraph& other);
    ~SetGraph() override = default;
    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;
};
