#include<bits/stdc++.h>
using namespace std;

int adj[1001][1001];
int visit[1001];
int node, edge;

void BFS(int start){
	// Initial step of BFS
	visit[start] = 1;
	cout << start << " ";
	queue<int> q;
	q.push(start);

	//Repeating Step of BFS
	while(!q.empty()){
		int x = q.front();
		q.pop();

		for(int j = 1; j <= node; j++){
			if(adj[x][j] != 0 && visit[j] == 0){
				visit[j] = 1;
				cout << j << " ";
				q.push(j);
			}
		}
	}


}

int main(){

	cin >> node >> edge;
	int u, v;
	for(int i = 1; i <= edge; i++){
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	BFS(1);

	return 0;
}