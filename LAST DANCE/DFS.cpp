// Author: Kallol Das Kushol
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visit[1001];
int node, edge;

void DFS(int start) {
	visit[start] = 1;
	cout << start << " ";
	stack<int> s;
	s.push(start);

	while(!s.empty()) {
		int x = s.top();

		for(int j = 0; j < adj[x].size(); j++){
			int node = adj[x][j];
			if(visit[node] == 0){
				visit[node] = 1;
				cout << node << " ";
				s.push(node);

				j = 0;
				x = s.top();
			}
		}
		s.pop();
	}
}

void DFS_Rec(int start) {
	cout << start << " ";
	visit[start] = 1;
	for(int i = 0; i < adj[start].size(); i++){
		int node = adj[start][i];
		if(visit[node] == 0) {
			visit[node] = 1;
			DFS_Rec(node);
		}
	}
}

int main(){

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



// // Author: Kallol Das Kushol
// #include <bits/stdc++.h>
// using namespace std;

// int adj[1001][1001];
// int visit[1001];
// int node, edge;

// void DFS(int start) {
// 	visit[start] = 1;
// 	cout << start << " ";
// 	stack<int> s;
// 	s.push(start);

// 	while(!s.empty()){
// 		for(int j = 1; j <= node; j++){
// 			int x = s.top();
// 			if(adj[x][j] != 0 && visit[j] == 0){
// 				visit[j] = 1;
// 				cout << j << " ";
// 				s.push(j);
// 				j = 1;
// 			}
// 		}
// 		s.pop();
// 	}
// }

// int main(){

// 	cin >> node >> edge;

// 	int u, v;
// 	for(int i = 1; i<=edge; i++){
// 		cin >> u >> v;
// 		adj[u][v] = 1;
// 		adj[v][u] = 1;
// 	}

// 	DFS(1);


// 	return 0;
// }