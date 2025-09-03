#include <bits/stdc++.h>
// https://ideone.com/Oko0Eh
using namespace std;

int graph[1001][1001]; // size depends on n
int visit[1001];
int node, edge;

void DFS_Stack(int start){

    //! Initial Step
    visit[start] = 1; // index number => node number
    cout << start << " ";
    stack<int>S;
    S.push(start);


    //! Repeating step
    while(!S.empty()){

        int x = S.top(); // top always gets refreshed

        for(int j = 1; j <= node; j++){ //! j for checking node

            if(visit[j] == 0 && graph[x][j] != 0){
                visit[j] = 1;
                cout << j << " ";

                S.push(j); // push the adjacent node onto the stack
                j = 1; // reset j to 1 to continue checking from the first node
            }
        }
        S.pop(); //! as it is DFS => pop after the loop gets end, means that the node is visited fully.
    }
}

void DFS_Rec(int start){
    visit[start] = 1;
    cout << start << " ";
    for(int j = 1; j <= node; j++){

        if(visit[j] == 0 && graph[start][j] != 0){
            
            visit[j] = 1;
            DFS_Rec(j);
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
    // DFS_Stack(1);
    DFS_Rec(1);
    

    return 0;
}