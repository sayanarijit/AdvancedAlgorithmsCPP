#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Vertex {
private:
    int data;
    bool visited;
    vector<Vertex*> neighbours;
public:
    Vertex(int d) { data = d; };

    int getData() { return data; };
    bool isVisited() { return visited; };
    vector<Vertex*> getNeighbours() { return neighbours; };

    void setVisited(bool v) { visited = v; };
    void addNeighbour(Vertex* v) { neighbours.push_back(v); };
};


class BFS {
public:
    void bfs(Vertex* source) {
        queue<Vertex*> vqueue;

        (*source).setVisited(true);
        vqueue.push(source);

        while ( ! vqueue.empty() ) {

            Vertex* vertex = vqueue.front();
            vqueue.pop();
            (*vertex).setVisited(true);

            cout << (*vertex).getData() << " ";

            vector<Vertex*> neighbours = (*vertex).getNeighbours();
            for (vector<Vertex *>::iterator itr = neighbours.begin();
                itr != neighbours.end(); ++itr) {
                if ( ! (*itr)->isVisited() ) {
                    vqueue.push(*itr);
                };
            }
            (*vertex).setVisited(false);
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

    v1.addNeighbour(&v2);
    v1.addNeighbour(&v4);
    v4.addNeighbour(&v5);
    v2.addNeighbour(&v3);

    BFS().bfs(&v1);
}