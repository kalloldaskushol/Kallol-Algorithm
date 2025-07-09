#include <bits/stdc++.h>
using namespace std;

int optimalMerge(vector<int> files) { // O(nlogn) complexity
    
    priority_queue<int, vector<int>, greater<int> > minHeap; // Build the min-heap
    for (int i = 0; i < files.size(); i++) {
        minHeap.push(files[i]);
    }
    int total_COST = 0; // initally total cost is 0.
    
    while(minHeap.size() > 1){ // I have to get minimum 2 for Merging 
        int first = minHeap.top(); // to get the 1st minimum element
        minHeap.pop();
        
        int second = minHeap.top(); // to get the 2nd minimum element
        minHeap.pop();
        
        int merge_COST = first + second; // Merge cost of both.
        total_COST = total_COST + merge_COST;

        minHeap.push(merge_COST); // push the Merge_Cost 
    }
    
    cout<< minHeap.top() << endl;
    return total_COST;
}

int main() {
  vector<int> files = {10, 20, 30, 5, 30};  // Making array by 5 arrays size

  int cost = optimalMerge(files);

  cout << "Minimum Cost: " << cost << endl;

  return 0;
}