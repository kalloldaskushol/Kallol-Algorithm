// Author: Kallol Das Kushol
#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;

	int profit[n], weight[n];
	for(int i = 0; i<n; i++)	cin >> profit[i];
	for(int i = 0; i<n; i++)	cin >> weight[i];

	int knap[n+1][m+1];
	for(int i = 0; i < n+1; i++)	knap[i][0] = 0;
	for(int j = 0; j < m+1; j++)	knap[0][j] = 0;

	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++) {
			if(weight[i-1] > j){
				knap[i][j] = knap[i-1][j]; 
			} else {
				knap[i][j] = max(
					knap[i-1][j],
					profit[	i-1	] + knap[  i-1	][	j - weight[i-1]	]);
			}
		}
	}

	// for(int i = 0; i < n+1; i++){
	// 	for(int j = 0; j < m+1; j++){
	// 		cout << knap[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << knap[n][m] << endl;

	int i = n, j = m;
	while(i > 0){
		if(knap[i][j] = knap[i-1][j]){
			cout << i << " Included " << endl;
			j = j - weight[i-1];
		}
		i--;
	}


	return 0;

}