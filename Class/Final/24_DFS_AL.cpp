// https://ideone.com/YazD02
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int visit[1001];
int node, edge;

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
            
            int x = graph[x][j];
            
            if(visit[x] == 0){ //if the node is unvisited
                visit[x] = 1;
                cout << x << " ";

                S.push(x);  //! push the x onto the stack
                j = 0; // reset j to 0 to continue checking from the first neighbor
                x = S.top(); // As its DFS, we need to explore the new node fully before popping
            }
        }
        S.pop();
    }
}

int DFS_Rec(int start){
    visit[start] = 1;
    cout << start << " ";
    for(int j = 0; j < graph[start].size(); j++){
        
        int x = graph[start][j];
        if(visit[x] == 0){
            DFS_Rec(x);
            visit[x] = 1;
        }
    }
}


int main(){

    cin >> node >> edge;
    int u, v;
    for(int i = 1; i <= edge; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS_Stack(1);
    // DFS_Rec(1);
    return 0;
}