#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Vertex;

struct Edge {
    double cost;
    Vertex* from;
    Vertex* to;
    Edge(Vertex* f, Vertex* t, double c) {
        from = f; to = t; cost = c;
    }
};

struct Vertex {
    int id;
    double distance;
    Vertex* parent;
    vector<Edge*> edges;
    Vertex(int i) {id = i; distance = numeric_limits<double>::max();}
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
            Vertex* vertex = pq.top();
            pq.pop();

            for(vector<Edge*>::iterator i = vertex->edges.begin(); i != vertex->edges.end(); ++i) {
                Vertex* u = (*i)->from;
                Vertex* v = (*i)->to;
                if (v->distance > u->distance + (*i)->cost) {
                    v->distance = u->distance + (*i)->cost;
                    v->parent = u;
                    pq.push(v);
                }
            }
        }
    }
};