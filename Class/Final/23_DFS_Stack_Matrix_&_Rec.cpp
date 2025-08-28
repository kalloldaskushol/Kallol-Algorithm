#include <bits/stdc++.h>
// https://ideone.com/Oko0Eh
using namespace std;

int graph[1001][1001]; // size depends on n
int visit[1001];
int n, e;

void DFS_Stack(int start){

    //! Initial Step
    visit[start] = 1; // index number => node number
    cout << start << " ";
    stack<int>S;
    S.push(start);


    //! Repeating step
    while( ! S.empty() ){
        
        for(int j = 1; j<=n; j++){ //! j is the picking node

            int x = S.top(); // top always gets refreshed
            if(visit[j] == 0 && graph[x][j] != 0){
                visit[j] = 1; // mark as visited
                cout << j << " ";
                S.push(j); // push the adjacent node onto the stack
                j = 1; //?? reset j to 1 to continue checking from the first node
            }
        }
        S.pop(); // pop after the loop gets end, means that the node is visited fully.
    }
}

void DFS_Rec(int start){
    visit[start] = 1;
    cout << start << " ";
    for(int j = 1; j <=n; j++){
        if(visit[j] == 0 && graph[start][j] != 0){
            DFS_Rec(j);
            visit[j] = 1;
        }
    }
}


int main(){

    cin >> n >> e;
    int u, v;
    for(int i = 1; i<=e; i++){
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    // DFS_Stack(1);
    DFS_Rec(1);
    

    return 0;
}