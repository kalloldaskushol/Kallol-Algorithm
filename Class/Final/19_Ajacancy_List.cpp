// ideone.com/ 6coiaX
#include <bits/stdc++.h>
using namespace std;

int main(){

    int node , edge; cin >> node >> edge;

    // need 2D vector and row static
    vector<int> graph[node+1];

    int u, v;
    for(int i = 1; i<=edge; i++){
        cin >> u >> v;
        graph[u].push_back(v); //! need to study in details
        graph[v].push_back(u);
    }

    // diff between both MUST
    for(int i = 1; i<=node; i++){ // node
        cout << i << " -> ";
        for(int j = 0; j<graph[i].size(); j++){ // value
            cout << graph[i][j] << " "; // node
        }
        cout << endl;
    }
    return 0;
}