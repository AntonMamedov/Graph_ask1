#include <memory>

#include "IGraph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

size_t vertexCount = 5;

int main() {
    std::shared_ptr<IGraph> mGraph(new MatrixGraph(vertexCount));

    mGraph->AddEdge(0, 3);
    mGraph->AddEdge(1, 0);
    mGraph->AddEdge(4, 0);
    mGraph->AddEdge(4, 2);
    mGraph->AddEdge(2, 1);
    mGraph->AddEdge(3, 2);
    mGraph->AddEdge(3, 4);

    auto vertexNum_4_NextVertex = mGraph->GetNextVertices(4);
    std::cout << "Vertex 4 next vertex: ";
    for (int i : vertexNum_4_NextVertex){
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::shared_ptr<IGraph> lGraph(new ListGraph(*mGraph));
    auto vertexNum_0_PrevVertex = lGraph->GetPrevVertices(0);
    std::cout << "Vertex 0 prev vertex: ";
    for (int i : vertexNum_0_PrevVertex){
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::shared_ptr<IGraph> sGraph( new SetGraph(*lGraph));
    sGraph->AddEdge(3, 0);
    vertexNum_0_PrevVertex = sGraph->GetPrevVertices(0);
    std::cout << "Vertex 0 prev vertex: ";
    for (int i : vertexNum_0_PrevVertex){
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::shared_ptr<IGraph> arcGraph(new ArcGraph(*sGraph));
    arcGraph->AddEdge(1, 2);
    auto vertexNum_1_nextVertex = arcGraph->GetNextVertices(1);
    std::cout << "Vertex 1 nex vertex: ";
    for (int i : vertexNum_1_nextVertex){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}
