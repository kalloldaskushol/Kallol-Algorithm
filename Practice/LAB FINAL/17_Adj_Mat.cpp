#include<bits/stdc++.h>
using namespace std;

int adj[10001][10001];
int node, edge;


int main(){

	cin >> node >> edge;

	int u, v;
	for(int i = 1; i <= edge; i++){
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	for(int i = 1; i <= node; i++){
		for(int j = 1; j <= node; j++){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}

}