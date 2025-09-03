#include <bits/stdc++.h>
using namespace std;

int main(){

	string s1, s2;

	static int LCS[1001][1001]; // fixed-size DP table
	while (1) {
		if (!getline(cin, s1)) break;   // first line of the pair
        if (!getline(cin, s2)) break;   // second line of the pair
		
		int n = s1.size(); // row
		int m = s2.size(); // col

		for (int i = 0; i < n+1; i++){ // initializing the first column to 0
			LCS[i][0] = 0;
		}
		for(int j = 0; j < m+1; j++){ // initializing the first row to 0
			LCS[0][j] = 0;
		}

		for(int i = 1; i < n+1; i++){ // loop is for filling the LCS table.....
			for(int j = 1; j < m+1; j++){ // loop is for comparing characters

				if(s1[i-1] == s2[j-1]){ // if characters match
					LCS[i][j] = 1 + LCS[i-1][j-1]; // if characters match ===> fill the table by adding 1 to the diagonal value
				} else { // if characters don't match
					LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]); // if characters don't match ===> fill the table with the maximum of the left and top cells
				}
			}
		}
		cout << LCS[n][m] << endl; // print the length of the longest common subsequence
	}

	return 0;
}