//! ⭐⭐⭐⭐⭐
//! ideone.com/x0UePM
//! Why we take n + 1 at row and col at graph 
/*Normally, if there are n nodes, we could use an n x n matrix.

But here we used n+1 for both rows and columns.

Reason: In competitive programming or graph problems, nodes are usually numbered starting from 1 instead of 0.*/

//! Row and col are dedicated to the node at array representation, and the value [i][j] at the slots are edges value
//! But not in LL same story -> row are static but col are dynamic. row are node and the value of [i][j] are also node at LL.
//! To store the weight in LL represenation we need a custom variable which is made by structure -> pair will be called from STL.
#include <bits/stdc++.h>
using namespace std;

int main(){

    int node, edge; cin >> node >> edge; // always need to take the edge value MUST
    
    int graph[node+1][node+1];
    memset(graph, 0, sizeof(graph));

    int u, v; // u -> start; v -> end;
    for(int i = 1; i <= edge; i++){ // i is the edge index not edge count.
        cin >> u >> v; //! both are node
        graph[u][v] = 1;
        graph[v][u] = 1; // as it is a indirected graph -> we have to make [u][v] and [v][u] = 1
    }

    for(int i = 1; i <= node; i++){ // both are node
        for(int j = 1; j <= node; j++){
            cout << graph[i][j] << " "; // connection
        }
        cout << endl;
    }

    return 0;
}  