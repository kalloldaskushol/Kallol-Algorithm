// ideone.com/Fputta
#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visit[1001];
int n, e;
vector<int>ans;

void DFS(int start){

    visit[start] = 1; // mark as visited
    for(int j = 1; j <= n; j++){ // j is the adjacent node
        if(graph[start][j] != 0 && visit[j] == 0){ // if there is an edge and not visited
            visit[j] = 1; //! mark as visited
            DFS(j);
        }
    }
    ans.push_back(start); // store the node in the answer vector    
}

int main(){

    cin >> n >> e;
    int u, v;
    for(int i = 1; i<=e; i++){
        cin >> u >> v;
        graph[u][v] = 1; // directed graph
    }
    
    for(int i = 1; i <= n; i++){
        if(visit[i] == 0){
            DFS(i);
        }
    }

    for(int i = ans.size() - 1; i >= 0; i--){ // print in reverse order
        cout << ans[i] << " ";
    }

    return 0;
}