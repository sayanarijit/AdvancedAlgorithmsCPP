#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
private:
    double cost;
    Vertex* left;
    Vertex* right;
public:
    Edge(Vertex* l, Vertex* r, double c) {
        left = l; right = r; cost = c;
    }

    double getCost() { return cost; }
    Vertex* getRight() { return right; }
    Vertex* getLeft() { return left; }
};

class Vertex {
private:
    int id;
    bool visited;
    vector<Edge*> edges;
public:
    Vertex(int i) { id = i; }

    int getId() { return id; }
    bool isVisited() { return visited; }
    vector<Edge*> getEdges() { return edges; }
    void addEdge(Edge* e) { edges.push_back(e); }
};

class Kruskal {
public:
    void calculateDistances(vector<Edge*> edges) {
        sort(edges.begin(), edges.end(),
            [](Edge *e1, Edge *e2) -> bool { return (*e1).getCost() < (*e2).getCost(); });

        for (vector<Edge*>::iterator i = edges.begin(); i != edges.end(); ++i ) {
            cout << (*i)->getCost() << endl;
        }
    }
};

int main() {
    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);
    Vertex v5 = Vertex(5);
    Vertex v6 = Vertex(6);

    vector<Edge*> edges;

    edges.push_back(&Edge(&v1, &v2, double(4)));
    edges.push_back(&Edge(&v1, &v2, double(2)));
    edges.push_back(&Edge(&v1, &v2, double(3)));
    edges.push_back(&Edge(&v1, &v2, double(7)));

    Kruskal().calculateDistances(edges);
}