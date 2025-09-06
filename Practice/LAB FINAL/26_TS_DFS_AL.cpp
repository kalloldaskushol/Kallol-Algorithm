#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visit[1001];
int node, edge;
vector<int> ans;

void DFS(int start){
	visit[start] = 1;
	for(int j = 0; j < adj[start].size(); j++){
		int adj_node = adj[start][j];

		if(visit[adj_node] == 0){
			DFS(adj_node);
		}
	}
	ans.push_back(start);
}

int main(){

	cin >> node >> edge;
	int u, v;

	for(int i = 1; i<=edge; i++){
		cin >> u >> v;
		adj[u].push_back(v); //! Directed Graph
	}

	for(int i = 1; i <= node; i++){
		if(visit[i] == 0){
			DFS(i);
		}
	}

	for(int i = ans.size()-1; i >= 0; i--){
		cout << ans[i] << " ";
	}

	return 0;
}