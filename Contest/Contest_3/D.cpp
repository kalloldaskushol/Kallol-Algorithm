#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int t; // taking the test case number
	cin >> t;

	while(t--){ // run the loop until the test case value becomes 0
		string s1, s2; // declaring the strings for comp
		cin >> s1 >> s2; // taking the input strings

		int m = s1.size(); // length of first string
		int n = s2.size(); // length of second string

		// s1 will be compared with s2
		// means s1 has to be changed so it will be placed in ROW.
		int edit[n + 1][m + 1]; // declaring the edit table

		for(int i = 0; i < n + 1; i++){ // loop is to initialize column
			edit[i][0] = i;
 		}
		for(int j = 0; j < m + 1; j++){ // loop is to initialize row
			edit[0][j] = j;
		}

		for(int i = 1; i < n+1; i++){ // loop is to fill the edit table
			for(int j = 1; j < m+1; j++){ // to compare characters
				if(s2[i-1] == s1[j-1]){ // if characters are same, we used s2[i-1] and s1[j-1] because we are comparing the current characters of both strings. and as the row holds s2 and column holds s1, s2 in row so we use s1[j-1];s1 in col so we use s1[i-1];
					 
					edit[i][j] = edit[i-1][j-1]; // if characters are same ----> take the value from diagonal.
				}
				else{
					edit[i][j] = 1 + min({edit[i-1][j], edit[i][j-1], edit[i-1][j-1]}); // if characters are not same ----> take the minimum of all three operations and add 1.
				}
			}
		}
		cout << edit[n][m] << endl; // print the edit distance
	}
	return 0;
}