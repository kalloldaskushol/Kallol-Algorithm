// https://ideone.com/YazD02
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int visit[1001];
int n, e;

//! need to modify
void DFS_Stack(int start){
    // initial step
    visit[start] = 1;
    cout << start << " ";
    stack<int> S;
    S.push(start);

    //! repeating step
    while (!S.empty()){
        int node = S.top();
        for(int j = 0; j<graph[node].size(); j++){
            
            int neighbor = graph[node][j];
            if(visit[neighbor] == 0){
                visit[neighbor] = 1;
                cout << neighbor << " ";
                S.push(neighbor);
                j = 0;
                int node = S.top();
            }
        }
        S.pop();
    }
}

// int DFS_Rec(int start){
//     visit[start] = 1;
//     cout << start << " ";
//     for(int j = 0; j < graph[start].size(); j++){
//         int neighbor = graph[start][j];
//         if(visit[neighbor] == 0){
//             DFS_Rec(neighbor);
//             visit[neighbor] = 1;
//         }
//     }
// }
int main(){

    cin >> n >> e;
    int u, v;
    for(int i = 1; i<=e; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS_Stack(1);
    // DFS_Rec(1);
    return 0;
}