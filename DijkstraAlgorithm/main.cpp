#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Vertex;

struct Edge {
    double cost;
    Vertex* target;
    Edge(Vertex* t, double c) {
        target = t; cost = c;
    }
};

struct Vertex {
    int id;
    double distance;
    Vertex* parent;
    vector<Edge*> edges;
    Vertex(int i) {
        id = i;
        parent = NULL;
        distance = numeric_limits<double>::max();
    }
};

struct CompareVertex {
    bool operator()(Vertex* v1, Vertex* v2) { return v1->distance < v2->distance; }
};

struct ShortestPath {
    void computePaths(Vertex* source) {
        source->distance = 0;
        priority_queue<Vertex*, vector<Vertex*>, CompareVertex> pq;
        pq.push(source);

        while( ! pq.empty() ) {
            auto vertex = pq.top();
            pq.pop();

            for(auto itr : vertex->edges) {
                auto target = itr->target;
                auto newCost = vertex->distance + itr->cost;
                if (target->distance > newCost) {
                    target->distance = newCost;
                    target->parent = vertex;
                    pq.push(target);
                }
            }
        }
    }

    vector<int> getShortestPathTo(Vertex* target) {
        auto vertex = target;
        vector<int> result;
        while( vertex != NULL ) {
            result.push_back(vertex->id);
            vertex = vertex->parent;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<Vertex*> vList;
    for(int i=0; i<3; i++) {
        vList.push_back(new Vertex(i+1));
    }
    vList[0]->edges.push_back(new Edge(vList[1], 1));
    vList[0]->edges.push_back(new Edge(vList[2], 1));
    vList[1]->edges.push_back(new Edge(vList[2], 1));

    ShortestPath shortestPath;
    shortestPath.computePaths(vList[0]);
    vector<int> result = shortestPath.getShortestPathTo(vList[2]);

    for(auto itr : result) {
        cout << itr << " ";
    }
    cout << endl;
}