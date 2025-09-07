#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visit[1001];
int node, edge;

void DFS(int start){
	visit[start] = 1;
	cout << start << " ";
	stack<int> s;
	s.push(start);

	while(!s.empty()){
		int x = s.top(); // x has the mother node
		for(int j = 0; j < adj[x].size(); j++){ // neighour check

			int neigbhour = adj[x][j];
			if(visit[neigbhour] == 0){
				visit[neigbhour] = 1;
				cout << neigbhour << " ";
				s.push(neigbhour);

				j = 0; // col
				x = s.top();
			}
		}
		s.pop();
	}
}

void DFS_Rec(int start) {
	cout << start << " ";
	visit[start] = 1;
	for(int j = 0; j < adj[start].size(); j++){
		int node = adj[start][j];
		if(visit[node] == 0){
			visit[node] = 1;
			DFS_Rec(node);
		}
	}
}

int main() {

	cin >> node >> edge;
	int u, v;

	for(int i = 1; i <= edge; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS_Rec(1);

	return 0;
}