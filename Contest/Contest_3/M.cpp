#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int visited[10001];
int maxDistance, farthestNode; // for storing the maximum distance and the farthest node found

void DFS(int start, int distance){
	visited[start] = 1;
	if(distance > maxDistance){
		maxDistance = distance;
		farthestNode = start; // Update the farthest node again
	}

	for(int j = 0; j < adj[start].size(); j++){
		int neighbor = adj[start][j];
		if(!visited[neighbor]){
			DFS(neighbor, distance + 1); // distance + 1 cz we are moving to the next level
		}
	}
}

int main(){

	int n; // number of nodes
	cin >> n;

	// if n is 0, the tree is empty
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}

	// Read the edges
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	maxDistance = -1;
	DFS(1, 0);
	
	return 0;
}