#include <bits/stdc++.h>
using namespace std;

int optimalMerge(vector<int> files) { // nlogn complexity
  priority_queue<int, vector<int>, greater<int> > minHeap;
  for (int i = 0; i < files.size(); i++) {
    minHeap.push(files[i]);
  }
  int totalCOST = 0;
  while(minHeap.size() > 1){ // i have to get minimmum 2 for marging 
    int first = minHeap.top();
    minHeap.pop();
    int second = minHeap.top();
    minHeap.pop();
    int margeCOST = first + second;
    totalCOST = totalCOST + margeCOST;

    minHeap.push(margeCOST);
  }
  cout<< minHeap.top() << endl;
  return totalCOST;
}

int main() {
  vector<int> files = {10, 20, 30, 5, 30};  // making array by 5 arrays size

  int cost = optimalMerge(files);

  cout << "Minimum Cost: " << cost << endl;

  return 0;
}