// ideone.com/HTRY7s
#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001]; //! but default zero
int visit[1001];
int node, edge;

void BFS(int start){ // Why breadth first search

    // Initial Step
    visit[start] = 1;
    cout << start << " ";
    queue<int> Q;
    Q.push(start);

    // Repeating Step
    while(!Q.empty()){

        int x = Q.front();
        Q.pop();

        for(int j = 1; j <= node; j++){
            if(visit[j] == 0 &&  graph[x][j] != 0){ // not visited & no connection
                visit[j] = 1;
                cout << j << " ";
                Q.push(j);
            }
        }
    }

}

int main(){

    cin >> node >> edge;
    int u, v;
    for(int i = 1; i<=edge; i++){
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    BFS(1);

    return 0;
}