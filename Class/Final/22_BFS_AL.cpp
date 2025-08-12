#include <bits/stdc++.h>
// https://ideone.com/buke19
using namespace std;
// need to correct
//! BFS is O(n2) on complate graph

vector<int> graph[1001]; //! but default zero
int visit[1001];
int node, edge;

void BFS(int start){ // Why bread first search
    
    // Initial Step
    visit[start] = 1;
    cout << start << " ";
    queue<int> Q;
    Q.push(start);
    
    while(!Q.empty()){
        int x = Q.front();
        cout << x << " ";
        Q.pop();

        for(int j = 0; j < graph[x].size(); j++){
            int nd = graph[x][j]; //! now node is this, prev it was connection. we dont need connection in L.L.
            
            if( visit[nd] == 0){
                visit[nd] = 1;
                Q.push(nd);
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