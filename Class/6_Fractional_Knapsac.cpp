// ⭐⭐⭐⭐⭐ LAB FINAL
#include <bits/stdc++.h>
using namespace std;

struct knap {
  int object;
  double p_by_w;
};

bool comparep_by_w(knap n1, knap n2) {
  if (n1.p_by_w > n2.p_by_w)
    return true;
  else
    return false;
}

int main() {
  int n, m;
  // n = number of objeect
  // m total weight
  cin >> n >> m;

  int profit[n];
  int weights[n];

  for (int i = 0; i < n; i++) {
    cin >> profit[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }

  knap sack[n];
  for (int i = 0; i < n; i++) {
    sack[i].object = i;
    sack[i].p_by_w = double(profit[i] / double(weights[i]));
  }

  sort(sack, sack + n, comparep_by_w);

  int RW = m;
  double X[n];
  memset(X, 0.0, sizeof(X));

  int i = 0;

  while (RW > 0) {
    if (RW >= weights[sack[i].object]) {
      X[sack[i].object] = 1;
      RW = RW - weights[sack[i].object];
      i++;
    } else {
      X[sack[i].object] = double(RW) / double(weights[sack[i].object]);
      RW = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << X[i] << " ";
  }
  cout << endl;

  double maxprofit = 0;
  for (int i = 0; i < n; i++) {
    maxprofit = maxprofit + (X[i] * double(profit[i]));
  }
  cout << maxprofit << endl;

  return 0;
}