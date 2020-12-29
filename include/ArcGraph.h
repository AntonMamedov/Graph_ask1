#pragma once
#include "IGraph.h"

class ArcGraph final : public IGraph{
private:
    std::vector<std::pair<int, int>> arcArr;
    size_t vertexCount;
public:
    explicit ArcGraph(size_t vCount);
    explicit ArcGraph(const IGraph& other);
    ~ArcGraph() override = default;
    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;
};
