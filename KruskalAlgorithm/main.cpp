#include <bits/stdc++.h>

using namespace std;

struct Vertex;

struct Edge {
    double cost;
    Vertex* left;
    Vertex* right;
    Edge(Vertex* left, Vertex* right, double cost):
        left(left), right(right), cost(cost) {};
};

struct Vertex {
    int id;
    double height;
    Vertex* parent = NULL;
    Vertex(int id): id(id) {};
};

Vertex* find(Vertex* v) {
    if (v->parent == NULL)
        return v;
    v->parent = find(v->parent);
    return v->parent;
}

void doUnion(Vertex* v1, Vertex* v2) {
    Vertex* root1 = find(v1);
    Vertex* root2 = find(v2);
    if ( root1 == root2 )
        return;
    if ( root1->height > root2->height )
        root2->parent = root1;
    else if( root2->height > root1->height )
        root1->parent = root2;
    else {
        root2->parent = root1;
        root1->height++;
    }
}

struct Kruskal {
    double minimumCost;
    vector<Edge *> mst;

    void spanningTree(vector<Edge*> edges) {
        minimumCost = 0;
        mst = {};

        sort(edges.begin(), edges.end(), [](auto *e1, auto *e2)->bool {
            return e1->cost < e2->cost;
        });

        for (auto itr : edges) {
            Vertex* rootLeft = find(itr->left);
            Vertex* rootRight = find(itr->right);
            if ( rootLeft != rootRight ) {
                mst.push_back(itr);
                doUnion(rootLeft, rootRight);
                minimumCost += itr->cost;
            }
        }
    }
};

int main() {
    vector<Vertex*> vList;
    for (int i=1; i<9; i++)
        vList.push_back(new Vertex(i));

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

    Kruskal kruskal = Kruskal();
    kruskal.spanningTree(edges);

    for (auto itr : kruskal.mst)
        cout << itr->left->id << " " << itr->right->id << " -- ";
    cout << endl;

    return 0;
}