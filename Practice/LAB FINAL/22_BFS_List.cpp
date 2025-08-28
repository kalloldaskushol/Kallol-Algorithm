#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visit[1001];
int node, edge;

void BFS(int start){
	//Inital Step
	visit[start] = 1;
	cout << start << " ";
	queue<int> q;
	q.push(start);

	//repeating step
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		for(int j = 0; j < adj[x].size(); j++){

			int neighbour = adj[x][j];
			if( visit[neighbour] == 0){
				visit[neighbour] = 1;
				cout << neighbour << " ";
				q.push(neighbour);
			}
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

	BFS(1);

    return 0;
}