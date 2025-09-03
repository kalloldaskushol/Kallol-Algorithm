#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n; // Length of the input sequence
		cin >> n;
		int list[1001];
		for(int i = 0; i < n; i++){ 
			cin >> list[i];	// For input
		}
		int LIS[1001];
		// Compute the Longest Increasing Subsequence (LIS)
		for(int i = 0; i < n; i++){
			LIS[i] = 1; // Each element is an increasing subsequence of length 1
			for(int j = 0; j < i; j++){
				if(list[j] <= list[i]){
					LIS[i] = max(LIS[i], LIS[j] + 1);
				}
			}
		}

		// Find the maximum length of the LIS
		int maxLIS = 0;
		for(int i = 0; i < n; i++){
			maxLIS = max(maxLIS, LIS[i]);
		}
		cout << maxLIS << endl;
	}

	return 0;
}