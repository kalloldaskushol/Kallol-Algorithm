#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;
	int coin[n];

	//	input coin array
	for(int i = 0; i < n; i++)	cin >> coin[i];

	long long int dp[n+1][m+1];

	for(int i = 0; i < n+1; i++)	dp[i][0] = 0;
	for(int j = 1; j < m+1; j++)	dp[0][j] = INT_MAX;

	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++){
			if(coin[i-1] > j){
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coin[i-1]]); //! we need i now not i-1
			}
		}
	}

	// for(int i = 0; i < n+1; i++){
	// 	for(int j = 0; j < m+1; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << dp[n][m] << endl;

	int i = n, j = m;
	while(i > 0){
		while(dp[i][j] != dp[i-1][j]){
			cout << coin[i-1] << " selected " << endl;
			j = j - coin[i-1];
		}
		i--;
	}

	return 0;
}