#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Vertex {
    int data;
    bool visited;
    vector<Vertex *> neighbours;
    Vertex(int d) { data = d; };
};

struct DFS {
    void dfsNormal(Vertex* source) {
        stack<Vertex*> vstack;

        source->visited = true;
        vstack.push(source);
        
        while( ! vstack.empty() ) {
            auto vertex = vstack.top();
            vstack.pop();
            
            vertex->visited = true;
            cout << vertex->data << " ";

            for (auto itr : vertex->neighbours)
                if ( ! itr->visited )
                    vstack.push(itr);
        }
        cout << endl;
    }

    void dfsRecursive(Vertex* source) {
        source->visited = true;
        cout << source->data << " ";

        for (auto itr : source->neighbours)
            if ( ! itr->visited )
                dfsRecursive(itr);
        source->visited = false;
    }
};

int main() {
    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);
    Vertex v5 = Vertex(5);

    v1.neighbours.push_back(&v2);
    v1.neighbours.push_back(&v3);
    v3.neighbours.push_back(&v4);
    v4.neighbours.push_back(&v5);

    DFS dfs = DFS();
    dfs.dfsNormal(&v1);
    dfs.dfsRecursive(&v1);
    return 0;
}