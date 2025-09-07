// Author: Kallol Das Kushol
//! all conditions are on v and work are at u

#include <bits/stdc++.h>
using namespace std;

int adj[1001][1001];
int visit[1001];
bool isAP[1001];
int dis[1001], low[1001];
int timer = 0;
int node, edge;

void DFS(int u, int parent){
	visit[u] = 1;
	low[u] = dis[u] = ++timer;
	
	int child = 0;

	for(int v = 1; v <= node; v++){
		//! v connected & non-visited
		if(adj[u][v] != 0 && visit[v] == 0){
			child++;
			DFS(v,u);
			
			low[u] = min(low[v], low[u]);

			// not root && follows rule of AP
			if(parent != -1 && dis[u] <= low[v]) {
				isAP[u] = true;
			}
		//! v is connected & not parent
		} else if (adj[u][v] != 0 && v != parent){
			low[u] = min(dis[v], low[u]);
		}
	}

	//! now time to work with root
	if(parent == -1 && child > 1){
		isAP[u] = true;
	}
}

int main(){

	cin >> node >> edge;
	int u, v;
	for(int i = 0; i <= edge; i++){
		cin >> u >> v;
		adj[u][v]= 1;
		adj[v][u]= 1;
	}

	DFS(1, -1);

	for(int i = 1; i <= node; i++){
		if(isAP[i]){
			cout << i << " is an AP" << endl;
		}
	}
	return 0;
}