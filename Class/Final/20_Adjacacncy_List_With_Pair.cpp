// ideone.com/soLtJI
#include <bits/stdc++.h>
using namespace std;

int main(){

    int node , edge; cin >> node >> edge;

    // need 2D vector and row static
    vector<pair<int, int> > graph[node+1];

    int u, v, w;
    for(int i = 1; i<=edge; i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w)); //! need to study in details
        graph[v].push_back(make_pair(u,w));
    }

    // diff between both MUST
    for(int i = 1; i<=node; i++){ // node
        cout << i << " -> ";
        for(int j = 0; j<graph[i].size(); j++){ // value
            cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ") "; // node
        }
        cout << endl;
    }
    return 0;
}