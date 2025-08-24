//! Weighted graph with adjancacy matrix.
//! ⭐⭐⭐⭐⭐
//! ideone.com/L70v39
#include <bits/stdc++.h>
using namespace std;

int main(){

    int node, edge; cin >> node >> edge; // always need to take the edge value MUST
    
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