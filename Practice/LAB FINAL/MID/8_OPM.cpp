#include <bits/stdc++.h>
using namespace std;

int OPM(vector<int> files){
	priority_queue<int, vector<int>, greater<int> > minHeap;

	for(int i = 0; i < files.size(); i++){
		minHeap.push(files[i]);
	}
	int totol_Cost = 0;

	while(minHeap.size() > 1){
		int first = minHeap.top();
		minHeap.pop();
		int second = minHeap.top();
		minHeap.pop();

		int merge_Cost = first + second;

		totol_Cost += merge_Cost;

		minHeap.push(merge_Cost);
	}
	cout << minHeap.top() << endl;
	return totol_Cost;
}

int main(){

	vector<int> files = {5, 10, 20, 30, 30};
	
	int cost = OPM(files);
	
	cout << cost << endl;

	return 0;
}