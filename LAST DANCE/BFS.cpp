// #include<bits/stdc++.h>
// using namespace std;

// int adj[1001][1001];
// int visited[1001];
// int node, edge;

// void BFS(int start) {
// 	visited[start] = 1;
// 	cout << start << " ";
// 	queue<int> q;
// 	q.push(start);

// 	while(!q.empty()){
// 		int x = q.front();
// 		q.pop();

// 		for(int j = 1; j <= node; j++) {
// 			if(adj[x][j] != 0 && visited[j] == 0){
// 				visited[j] = 1;
// 				cout << j << " ";
// 				q.push(j);
// 			}
// 		}
// 	}
// }

// int main() {

// 	cin >> node >> edge;

// 	int u, v;
// 	for(int i = 1; i<=edge; i++){
// 		cin >> u >> v;
// 		adj[u][v] = 1;
// 		adj[v][u] = 1;
// 	}

// 	BFS(1);

// 	return 0;
// }


// Author: Kallol Das Kushol
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> adj[1001];
// int visited[1001];
// int node, edge;

// void BFS(int start) {
// 	visited[start] = 1;
// 	cout << start << " ";
// 	queue<int> q;
// 	q.push(start);

// 	while(!q.empty()){
// 		int x = q.front();
// 		q.pop();

// 		for(int j = 0; j < adj[x].size(); j++) {
// 		int node = adj[x][j];
// 		if(visited[node] == 0) {
// 			visited[node] = 1;
// 			cout << node << " ";
// 			q.push(node);
// 		}
// 	}
// 	}
// }

// int main(){

// 	cin >> node >> edge;
// 	int u, v;

// 	for(int i = 1; i <= edge; i++){
// 		cin >> u >> v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}

// 	BFS(1);

// 	return 0;
// }
