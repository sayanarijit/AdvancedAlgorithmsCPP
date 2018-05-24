#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex;

struct Edge {
    double cost;
    Vertex* left;
    Vertex* right;
    Edge(Vertex* l, Vertex* r, double c) {
        left = l; right = r; cost = c;
    }
};

struct Vertex {
    int id;
    double totalCost;
    double height;
    Vertex* parent;
    Vertex(int i) {
        id = i; parent = NULL;
    }
};

Vertex* find(Vertex* v) {
    if (v->parent == NULL) { return v; }
    v->parent = find(v->parent);
    return v->parent;
}

void doUnion(Vertex* v1, Vertex* v2) {
    Vertex* root1 = find(v1);
    Vertex* root2 = find(v2);
    if ( root1 == root2 ) { return; }
    if ( root1->height > root2->height ) {
        root2->parent = root1;
    } else if( root2->height > root1->height ) {
        root1->parent = root2;
    } else {
        root2->parent = root1;
        root1->height++;
    }
}

struct Kruskal {

    void spanningTree(vector<Edge*> edges) {
        vector<Edge*> mst;

        sort(edges.begin(), edges.end(),
            [](Edge* e1, Edge* e2) -> bool { return e1->cost < e2->cost; });

        for (vector<Edge*>::iterator i = edges.begin(); i != edges.end(); ++i) {
            Vertex* rootLeft = find((*i)->left);
            Vertex* rootRight = find((*i)->right);
            if ( rootLeft != rootRight ) {
                mst.push_back(*i);
                doUnion(rootLeft, rootRight);
            }
        }

        for (vector<Edge*>::iterator i = mst.begin(); i != mst.end(); ++i) {
            cout << (*i)->left->id << " " << (*i)->right->id << " -- ";
        }
        cout << endl;
    }
};

int main() {
    vector<Vertex*> vList;
    for (int i=1; i<9; i++) {
        vList.push_back(new Vertex(i));
    }

    vector<Edge*> edges;
    edges.push_back(new Edge(vList[0], vList[1], double(1)));
    edges.push_back(new Edge(vList[0], vList[2], double(10)));
    edges.push_back(new Edge(vList[1], vList[2], double(1)));
    edges.push_back(new Edge(vList[1], vList[5], double(13)));
    edges.push_back(new Edge(vList[1], vList[3], double(2)));
    edges.push_back(new Edge(vList[2], vList[4], double(5)));
    edges.push_back(new Edge(vList[2], vList[3], double(2)));
    edges.push_back(new Edge(vList[3], vList[4], double(4)));
    edges.push_back(new Edge(vList[3], vList[5], double(6)));
    edges.push_back(new Edge(vList[3], vList[6], double(3)));
    edges.push_back(new Edge(vList[4], vList[6], double(6)));
    edges.push_back(new Edge(vList[5], vList[6], double(2)));
    edges.push_back(new Edge(vList[5], vList[7], double(3)));
    edges.push_back(new Edge(vList[6], vList[7], double(6)));

    Kruskal().spanningTree(edges);

    for (vector<Vertex*>::iterator i = vList.begin(); i != vList.end(); ++i) {
        cout << (*i)->id << " " << (*i)->parent << endl;
    }

    return 0;
}