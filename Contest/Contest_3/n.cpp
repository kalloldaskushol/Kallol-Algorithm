#include <bits/stdc++.h>
using namespace std;

int visit[10001]; // for visited node checkk
vector<int> graph[10001]; // making list

int BFS(int start){ // bfs
	int check = 0; // for counting visited nodes
	queue<int> q; // for BFS queue is needed
	visit[start] = 1; // mark the start node as visited
	q.push(start); // push the start node into the queue

	while(!q.empty()){ // while the queue is not empty
		int node = q.front(); // get the front node
		q.pop(); // remove the front node from the queue
		check++; // update the count of visited nodes

		for(int j = 0; j < graph[node].size(); j++){
			int x = graph[node][j]; // get the adjacent node

			if(visit[x] == 0){ // if the adjacent node is not visited
				visit[x] = 1; // mark it as visited
				q.push(x); // push it into the queue
			}
		}
	}
	return check; // return the count of visited nodes
}

int main(){

	int node, edge;
	cin >> node >> edge; 
 
	bool self_loop = false; // to check if there is any self loop

	int u, v; // node at two sides of an edge
	for (int i = 0; i < edge; i++) {
		cin >> u >> v;
		if(u == v) self_loop = true; 
		graph[u].push_back(v); // connecting u to v
		graph[v].push_back(u); // connecting v to u
	}

	if(edge != node - 1 || self_loop){
        cout << "NO";
        return 0;
    }
	int check_Node = BFS(1);
	if (check_Node == node) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}