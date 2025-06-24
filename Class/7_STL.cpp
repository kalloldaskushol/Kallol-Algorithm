// ideone.com/vjzAYC
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec;  // 1D array // dynamic// created with linked list but acts
                    // like an array
  // vector<int>vec[5]; //2D array , column is dynamic but the array row is
  // fixed. vector<int>vec(5); //1D array & size fixed vector<vector<int>>vec;
  // //2D array & dynamic

  // vector<int>vec;
  // vector<string>vec(5); // 5 size of string array, we can take 5 strings, it
  // works like 2d as string keeps at stack vector<float>f[8];
  // vector<vector<char> >ch; // 2d
  // vector<vector<string> >str; // 3d

  //   vec.push_back(10);
  //   vec.push_back(20);
  //   vec.pop_back();

  //   for (int i = 0; i < vec.size(); i++) {
  //     cout << vec[i] << " ";
  //   }

  //   vector<int> v[10];
  //   v[4].push_back(100);

  //   for (int i = 0; i < v[4].size(); i++) {
  //     cout << v[4][i] << " ";
  //   }

  // maxheap
  //   priority_queue<int>maxHeap;

  //   maxHeap.push(50);
  //   maxHeap.push(15);
  //   maxHeap.push(20);
  //   maxHeap.push(60);

  //   while(maxHeap.size() > 0){
  //     cout << maxHeap.top() << " ";
  //     maxHeap.pop();
  //   }

  // min_heap
  priority_queue<int, vector<int>, greater<int> > minHeap;

  minHeap.push(20);
  minHeap.push(15);
  minHeap.push(40);
  minHeap.push(25);

  while (minHeap.size() > 0) {
    cout << minHeap.top() << " ";
    minHeap.pop();
  }
  return 0;
}