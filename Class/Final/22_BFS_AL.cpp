// https://ideone.com/buke19
/*
BFS complexity: O(V + E)
For complete graph: O(V^2)
*/
#include <bits/stdc++.h>
using namespace std;
//! BFS is O(n2) on complete graph => because every node is connected to every other node
//! In general, BFS is O(V + E) => because we explore all vertices and edges

vector<int> graph[1001]; //! but default zero
int visit[1001];
int node, edge;

void BFS(int start){
    
    // Initial Step
    visit[start] = 1;
    cout << start << " ";
    queue<int> Q;
    Q.push(start);

    // repeating step
    while(!Q.empty()){
        int x = Q.front();
        // cout << x << " ";
        Q.pop();

        for(int j = 0; j < graph[x].size(); j++){
            int node = graph[x][j]; //! now node is this, prev it was connection. we dont need connection in L.L.
            
            if( visit[node] == 0){
                cout << node << " ";
                visit[node] = 1;
                Q.push(node);
            }
        }
    }

}

int main(){

    cin >> node >> edge;
    int u, v;
    for(int i = 1; i<=edge; i++){
        cin >> u >> v;
        graph[u].push_back(v); // u row, 
        graph[v].push_back(u);
    }

    BFS(1);

    return 0;
}