// https://ideone.com/4rFaJ4
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int profit[n];
  int weight[n];
  for (int i = 0; i < n; i++) {
    cin >> profit[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int sack[n + 1][m + 1]; // row for items, column for capacity

  // for row zero
  for (int i = 0; i < n + 1; i++) { //! Must be n + 1 to get the last item
    sack[i][0] = 0; // (item 0 → profit 0)
  }
  // for col zero
  for (int j = 0; j < m + 1; j++) {
    sack[0][j] = 0; // (weight 0 → profit 0)
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {  //As the array is 1 based and the i-1 th will represent the current element correctly. 
      // If the current item is too heavy for capacity j, we can’t take it, so just take the previous value.
      if (weight[i - 1] > j) {
        sack[i][j] = sack[i - 1][j];
      } else {
        sack[i][j] = max(sack[i - 1][j], sack[i - 1][j - weight[i - 1]] + profit[i - 1]);
        // now if we take the item then the profit = profit for the current item + profit got by the remaing capacity. if the taken_item profit is less than our previous profit then we wont take it. Means the MAX one will be considered
      }
    }
  }
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      cout << sack[i][j] << " ";
    }
    cout << endl;
  }

  cout << sack[n][m] << endl;
  int i = n, j = m;

  while (i > 0) {
    if (sack[i][j] == sack[i - 1][j]) {
      i = i - 1;
      continue;
    } else {
      cout << "Product " << i << " is selected" << endl;
      j = j - weight[i - 1];
      i = i - 1;
    }
  }
}