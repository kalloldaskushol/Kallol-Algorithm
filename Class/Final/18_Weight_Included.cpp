//! Weighted graph with adjancacy matrix.
//! ⭐⭐⭐⭐⭐
//! ideone.com/
//! Why we take n + 1 at row and col at graph 
//! Row and col are dedicated to the node at array representation, and the value [i][j] at the slots are edges value
//! But not in LL same story -> row are static but col are dynamic. row are node and the value of [i][j] are also node at LL.
//! To store the weight in LL represenation we need a custom variable which is made by structure -> pair will be called from STL.
#include <bits/stdc++.h>
using namespace std;

int main(){

    int node, edge; cin >> node >> edge; // alwasy need to take the edge value MUST
    
    int graph[node+1][node+1];
    memset(graph, 0, sizeof(graph));

    int u, v, w; // u -> start; v -> end;
    for(int i = 1; i <= edge; i++){
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // both are connected so they are indirected graph
    }

    for(int i = 1; i <= node; i++){ // both are node
        for(int j = 1; j <= node; j++){
            cout << graph[i][j] << " "; // connection
        }
        cout << endl;
    }

    return 0;
}  