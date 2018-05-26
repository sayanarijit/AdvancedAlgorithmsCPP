# Prim's Algorithm

* Used to find the sub-tree (i.e. Minimum Spanning Tree) to visit all nodes at minimum cost in an undirected graph (i.e. collection of Spanning Trees).
* Vertex based algorithm: Starts adding the smallest edge to the spanning tree from a given vertex.
* 2 implementations: ***Lazy*** and ***Eager***
* ***Lazy:*** Adds the neighbour edge to heap without deleting it's content.
* ***Eager:*** Keeps updating the heap if the distance from a vertex to the MST has changed.
* When number of edges is more than number of vertexes, it is significantly faster than Kruskal Algorithm.
* Time complexity: `O(E*logE)` but need additional memory: `O(E*logV)`.
* Worst case running time: `O(E*logV)`