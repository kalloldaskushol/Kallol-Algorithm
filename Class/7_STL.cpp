  // ideone.com/vjzAYC
  #include <bits/stdc++.h>
  using namespace std;

  int main() {
    vector<int> vec;  // 1D array, dynamic, created with linked list but acts like an array
    
    vector<int>vec[5]; //An array of 5 vectors -> its like a 2D structure where wors are fixed and its 5, columns are dynamic.

    vector<int>vec(5); //1D array of size 5.

    vector<vector<int>>vec; //2D vector where row & col both are dynamic

    vector<string>vec(5); // An string containing vector of 5 size.We can take 5 strings in it, it works like 2d as string keeps at stack.

    vector<float>f[8]; // An array of 8 float vectors
    vector<vector<char> >ch; // 2D vector of characters.
    vector<vector<string> >str; // 2D string vector but each string is of multiple character so er can say it is 3D. 

      vec.push_back(10);
      vec.push_back(20);
      vec.pop_back();

      for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
      }

      vector<int> v[10];
      v[4].push_back(100);

      for (int i = 0; i < v[4].size(); i++) {
        cout << v[4][i] << " ";
      }

    // maxheap
      priority_queue<int>maxHeap; // by default priority_queue makes a max-heap

      maxHeap.push(50);
      maxHeap.push(15);
      maxHeap.push(20);
      maxHeap.push(60);

      while(maxHeap.size() > 0){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
      }

    // min_heap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    // first int means -> we are storing integers in the heap.
    // then vector<int> means -> the elements inside the heap will be integer.
    // then greater<int> means -> it will make the smaller numbers come first.

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