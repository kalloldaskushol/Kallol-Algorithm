// Author: Kallol Das Kushol 
// https://ideone.com/k7K6p6
#include <bits/stdc++.h>
using namespace std;

//! due to DFS its TC(N+E)

int graph[1001][1001];
int visit[1001];
int dis[1001], low[1001];
bool isAP[1001];
int timer = 0;
int n, e;

void DFS(int u, int parent){

	//! we have entered the loop with node u
	visit[u] = 1;
	dis[u] = low[u] = ++timer; // Initialize discovery and low values by timer cz initialially same when it is entering. We dont know that it has an back edge or not.

	int child = 0; //to track the child number.

	for(int v = 1; v <= n; v++){ // node traversal => v is column & //! v is the checking node

		if( visit[v] == 0 && graph[u][v] != 0 ){ // not visited & there is a connection
			
			child++; //! Not got the point
			DFS(v, u); // normally in AP (u,v) call --> u parent and v is the child
					   // in the case we have first the child and 2nd the parent node --> DFS(v,u)

			//?? we will always update low[u].
			//* we are done with DFS, now set the low value of parent node u
			
			low[u] = min(low[u], low[v]);

			if(parent != -1 && dis[u] <= low[v]){ // If u is not root and its discovery time is less than or equal to low value of v
				isAP[u] = true;
			}

		} else if( graph[u][v] != 0 && v != parent ){ //! Back edge found => connected but visited
			low[u] = min(low[u], dis[v]); //! if back edge found -> we will update the low value of u with dis[v] means its parent node's discovery time
		}
	}

	if(parent  == -1 && child > 1){
		isAP[u] = true; //! means root is a articulation point.
	}
}

int main(){

	cin >> n >> e;
    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

	DFS(1, -1); // 1 has no parent, so its parent is -1

	for(int i = 1; i <= n; i++){
		if(isAP[i] == true){
			cout << i << " is an articulation point" << endl;
		}
	}

	return 0;
}