#include <bits/stdc++.h>
using namespace std;

int adj[1001][1001];
int visit[1001];
int node, edge;
vector<int> ans;

void DFS(int start){
	visit[start] = 1;

	for(int j = 1; j <= node; j++){
		if(visit[j] == 0 && adj[start][j] != 0){
			visit[j] = 1;
			DFS(j);
		}
	}
	ans.push_back(start);
}

int main(){

	int u, v;
	cin >> node >> edge;
	for(int i = 1; i <= edge; i++){
		cin >> u >> v;
		adj[u][v] = 1; // directed graph 
	}

	for(int i = 1; i <= node; i++){
		if(visit[i] == 0){
			DFS(i);
		}
	}

	for(int i = ans.size()-1; i>=0; i--){
		cout << ans[i] << " ";
	}

	return 0;
}