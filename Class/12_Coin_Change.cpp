// https://ideone.com/52SSe7
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int coin[n];

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    long long int dp_coin[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++) {
        dp_coin[i][0] = 0;
    }
    for (int j = 1; j < m + 1; j++) {
        dp_coin[0][j] = INT_MAX;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {

            if (coin[i - 1] > j) {
                dp_coin[i][j] = dp_coin[i - 1][j];
            } else {
                dp_coin[i][j] = min(dp_coin[i - 1][j], 1 + dp_coin[i][j - coin[i - 1]]);
            }
        }
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            cout << dp_coin[i][j] << " ";
        }
        cout << endl;
    }

    int i = n, j = m;
    while (i > 0) {
        while (dp_coin[i][j] != dp_coin[i - 1][j]) {
            j = j - coin[i - 1];
            cout << coin[i - 1] << " is selected" << endl;
            // continue;
        }
        i = i - 1;
  }
}