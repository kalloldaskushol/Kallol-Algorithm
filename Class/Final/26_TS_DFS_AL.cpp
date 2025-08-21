// https://ideone.com/vt1gx5

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int visit[1001];
int n, e;
vector<int> ans;

/*
i ---- j --> node at prev code
i ---- graph[i][j] --> node at this code

*/

void DFS(int start){ 

    visit[start] = 1; // mark as visited
    for(int j = 0; j < graph[start].size(); j++){ // not node
        int node = graph[start][j]; //! this is node
        if(visit[node] == 0){ // only this cz directed graph, and it takes only those which has not been visited
            DFS(node);
        }
    }
    ans.push_back(start);
}

int main(){

    cin >> n >> e;
    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        graph[u].push_back(v); // directed graph
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