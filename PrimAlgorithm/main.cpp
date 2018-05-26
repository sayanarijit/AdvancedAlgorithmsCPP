#include <bits/stdc++.h>

using namespace std;

struct Vertex;

struct Edge {
    double cost;
    Vertex* from;
    Vertex* to;
    Edge(Vertex* from, Vertex* to, double cost):
        from(from), to(to), cost(cost) {};
};

struct CompareEdge {
    bool operator()(Edge* e1, Edge* e2) { return e1->cost < e2->cost; }
};

struct Vertex {
    int id;
    Vertex* parent = NULL;
    vector<Edge*> edges;
    Vertex(int id): id(id) {};
};

struct Algorithm {
    double minimumCost;
    vector<Edge* > mst;

    void spanningTree(vector<Vertex*> unvisited, Vertex* source) {
        int minimumCost = 0;
        mst = {};
        priority_queue<Edge *, vector<Edge *>, CompareEdge> edges;

        auto vertex = source;
        auto found = find(unvisited.begin(), unvisited.end(), vertex);
        if ( found != unvisited.end() )
            unvisited.erase(found);
        
        while ( ! unvisited.empty() ) {
            for (auto e : vertex->edges)
                if ( find(unvisited.begin(), unvisited.end(), e->to) != unvisited.end() )
                    edges.push(e);
            
            auto edge = edges.top();
            edges.pop();
            mst.push_back(edge);
            minimumCost += edge->cost;
            
            auto found = find(unvisited.begin(), unvisited.end(), edge->to);
            if ( found != unvisited.end() ) {
                unvisited.erase(found);
                (*found)->parent = vertex;
            }
        }
    }
};

int main() {
    vector<Vertex*> vList;
    for (int i=0; i<3; i++)
        vList.push_back(new Vertex(i));

    vector<Edge*> edges;
    vList[0]->edges.push_back(new Edge(vList[0], vList[1], 1));
    vList[0]->edges.push_back(new Edge(vList[0], vList[2], 1));
    vList[1]->edges.push_back(new Edge(vList[1], vList[2], 10));
    vList[1]->edges.push_back(new Edge(vList[1], vList[0], 1));
    vList[2]->edges.push_back(new Edge(vList[2], vList[0], 1));
    vList[2]->edges.push_back(new Edge(vList[2], vList[1], 10));

    Algorithm prims;
    prims.spanningTree(vList, vList[2]);

    for (auto itr : prims.mst)
        cout << itr->from->id << " - " << itr->to->id << endl;

    return 0;
}