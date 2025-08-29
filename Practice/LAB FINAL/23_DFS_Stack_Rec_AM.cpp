#include<bits/stdc++.h>
using namespace std;

int adj[1001][1001];
int visit[1001];
int node, edge;

void DFS_Stack(int start){
	//! initial step
	visit[start] = 1;
	cout << start << " ";
	stack<int> s;
	s.push(start);

	//! repeating step
	while(!s.empty()){

		for(int j = 1; j <= node; j++){
			int x = s.top();
			if(visit[j] == 0 && adj[x][j] != 0){
				visit[j] = 1;
				cout << j << " ";
				s.push(j);
				j = 1;
			}
		}
		s.pop();
	}
}


void DFS_Rec(int start){
	visit[start] = 1;
	cout << start << " ";

	for(int j = 1; j <= node; j++){
		if(visit[j] == 0 && adj[start][j] != 0){
			visit[j] = 1;
			DFS_Rec(j);
		}
	}
}


int main(){

	cin >> node >> edge;
	
	int u, v;

	for(int i = 1; i<=edge; i++){
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	// DFS_Stack(1);
	DFS_Rec(1);

	return 0;
}