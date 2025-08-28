#include<bits/stdc++.h>
using namespace std;

int main(){

	int node, edge; cin >> node >> edge;

	vector<pair<int, int>> adj[node + 1];
	int u, v, w;
	for(int i = 1; i <= edge; i++){
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	for(int i = 1; i<=node; i++){
		cout << i << " -> ";

		for(int j = 0; j < adj[i].size(); j++){
			cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ") ";
		}
		cout << endl;
	}

	return 0;
}