# Kruskal Algorithm

* Used to find the sub-tree (i.e. Minimum Spanning Tree) to visit all nodes at minimum cost in an undirected graph (i.e. collection of Spanning Trees).
* Uses `find` and `union` method on a sorted list of edges.
* Also used in machine learning clustering algorithms like ***K means clustering***.
* Time complexity: `O(logV)` + `O(N*logN)` (time taken to sort edges).
* Worst case running time: `O(E*logE)`