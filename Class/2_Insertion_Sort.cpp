// ideone.com/zXzLmN
#include <bits/stdc++.h>
using namespace std;
// why it is called insertion sort => we are comparing then inserting it to the postition.
// what is the worst case of it => reverse sorted array (5,4,3,2,1)
void insertion(int n, int arr[]) {

  for (int i = 0; i < n; i++) {  // for picking values

    int pick = arr[i];
    int j = i - 1;  // comparing index

    while (j >= 0 && arr[j] > pick) {  // comparing index must be greater than 0 & comparing index value must be greater then pick 
      swap(arr[j + 1], arr[j]);
      j--;  // to check the previous index again
    }

    arr[j + 1] = pick;  // fix the position of every pick
    
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  insertion(n, arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}