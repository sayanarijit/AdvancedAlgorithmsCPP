#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    int data;
    bool visited;
    vector<Vertex*> neighbours;
    Vertex(int data): data(data) {};
};

struct BFS {
    void bfs(Vertex* source) {
        queue<Vertex*> vqueue;

        source->visited = true;
        vqueue.push(source);

        while ( ! vqueue.empty() ) {

            auto vertex = vqueue.front();
            vqueue.pop();
            vertex->visited = true;

            cout << vertex->data << " ";

            for (auto itr : vertex->neighbours)
                if ( ! itr->visited )
                    vqueue.push(itr);
        }
        cout << endl;
    }
};

int main() {
    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);
    Vertex v5 = Vertex(5);

    v1.neighbours.push_back(&v2);
    v1.neighbours.push_back(&v4);
    v4.neighbours.push_back(&v5);
    v2.neighbours.push_back(&v3);

    BFS().bfs(&v1);
    return 0;
}