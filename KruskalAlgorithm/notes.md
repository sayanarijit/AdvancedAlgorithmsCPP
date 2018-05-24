# Kruskal Algorithm

* Used to find the sub-tree to visit all nodes (i.e. Spanning Tree) at minimum cost in an undirected graph (i.e. Minimum Spanning Tree).
* Uses `find` and `union` method on a sorted list of edges.
* Also used in machine learning clustering algorithms like ***K means clustering***.
* Time complexity: `O(logV)` + `O(N*logN)` (time taken to sort edges).
* Worst case running time: `O(E*logE)`