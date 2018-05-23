#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Vertex {
private:
    int data;
    bool visited;
    vector<Vertex *> neighbours;
public:
    Vertex(int d) { data = d; };

    int getData() { return data; };
    bool isVisited() { return visited; };
    vector<Vertex *> getNeighbours() { return neighbours; };

    void setVisited(bool v) { visited = v; };
    void addNeighbour(Vertex *v) { neighbours.push_back(v); };
};

class DFS {
public:
    void dfsNormal(Vertex* source) {
        stack<Vertex*> vstack;

        (*source).setVisited(true);
        vstack.push(source);
        
        while( ! vstack.empty() ) {
            Vertex* vertex = vstack.top();
            vstack.pop();
            
            (*vertex).setVisited(true);
            cout << (*vertex).getData() << " ";

            vector<Vertex*> neighbours = (*vertex).getNeighbours();
            for (vector<Vertex*>::iterator itr = neighbours.begin();
                itr != neighbours.end(); ++itr) {
                if ( ! (*itr)->isVisited() ) {
                    vstack.push(*itr);
                }
            }
            (*vertex).setVisited(false);
        }
        cout << endl;
    }

    void dfsRecursive(Vertex* source) {
        (*source).setVisited(true);
        cout << (*source).getData() << " ";

        vector<Vertex*> neighbours = (*source).getNeighbours();

        for (vector<Vertex*>::iterator itr = neighbours.begin();
            itr != neighbours.end(); ++itr) {
            if ( ! (*itr)->isVisited() ) {
                dfsRecursive(*itr);
            }
        }
        (*source).setVisited(false);
    }
};

int main() {
    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);
    Vertex v5 = Vertex(5);

    v1.addNeighbour(&v2);
    v1.addNeighbour(&v3);
    v3.addNeighbour(&v4);
    v4.addNeighbour(&v5);

    DFS dfs = DFS();
    dfs.dfsNormal(&v1);
    dfs.dfsRecursive(&v1);
}