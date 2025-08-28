// https://ideone.com/YazD02
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int visit[1001];
int n, e;

void DFS_Stack(int start){
    // initial step
    visit[start] = 1;
    cout << start << " ";
    stack<int> S;
    S.push(start);

    //! repeating step
    while (!S.empty()){
        
        int x = S.top();
        
        for(int j = 0; j<graph[x].size(); j++){
            
            int neighbor = graph[x][j];
            
            if(visit[neighbor] == 0){ //if the node is unvisited
                visit[neighbor] = 1;
                cout << neighbor << " ";
                //! push the neighbor onto the stack
                S.push(neighbor);
                j = 0; // reset j to 0 to continue checking from the first neighbor
                x = S.top();
            }
        }
        S.pop();
    }
}

int DFS_Rec(int start){
    visit[start] = 1;
    cout << start << " ";
    for(int j = 0; j < graph[start].size(); j++){
        int neighbor = graph[start][j];
        if(visit[neighbor] == 0){
            DFS_Rec(neighbor);
            visit[neighbor] = 1;
        }
    }
}


int main(){

    cin >> n >> e;
    int u, v;
    for(int i = 1; i<=e; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // DFS_Stack(1);
    DFS_Rec(1);
    return 0;
}