#include<bits/stdc++.h>
using namespace std;

int main(){

	int node, edge;
	cin >> node >> edge;

	vector<int> adj[node + 1];

	int u, v;
	for(int i = 1; i <= edge; i++){

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= node; i++){
		cout << i << " -> ";
		for(int j = 0; j < adj[i].size(); j++){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}

}