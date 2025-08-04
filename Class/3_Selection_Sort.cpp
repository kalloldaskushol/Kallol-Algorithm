// ideone.com/NrZDUZ
#include <bits/stdc++.h>
using namespace std;
void selection(int n, int arr[]) {

  for (int i = 0; i < (n - 1); i++) {
    for (int j = i + 1; j < n; j++) {

      if (arr[j] < arr[i]) {
        swap(arr[i], arr[j]);
      }
      
      // For printing every steps:
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
}
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << endl;

  selection(n, arr);

  return 0;
}
/*
5
5 8 6 1 7
*/