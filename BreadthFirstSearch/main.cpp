#include <iostream>
#include <vector>

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


int main() {
    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    v1.addNeighbour(&v2);
    
    vector<Vertex*> n = v1.getNeighbours();
    vector<Vertex*>::iterator it;

    for (it = n.begin(); it != n.end(); ++it)
        cout << (*it)->getData();
}