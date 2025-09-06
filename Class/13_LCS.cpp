// https://ideone.com/mJSXxo
// LCS -> Tabulation
#include <bits/stdc++.h>
using namespace std;

int main(){

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int n = s1.size(); // row
    int m = s2.size(); // col

    int LCS[n+1][m+1];

    for(int i = 0; i<n+1; i++){ // row 0
        LCS[i][0] = 0;
    }
    for(int j = 0; j<m+1; j++){ // col 0
        LCS[0][j] = 0;
    }

    
    for(int i = 1; i<n+1; i++){ 
        for(int j = 1; j<m+1; j++){

            if(s1[i-1] == s2[j-1]){ // -1 so that we can cal the 0th index of s1 and s2.
                LCS[i][j] = 1 + LCS[i-1][j-1];
            } else {
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }

    // sequecnce
    string ans;
    int i = n, j = m;

    while (i > 0) {
        if (s1[i-1] == s2[j-1]) {
            ans.push_back(s2[j-1]); // character is part of LCS
            i = i - 1;              // move diagonally up-left
            j = j - 1;
        } else {
            if (LCS[i][j] == LCS[i-1][j]) { // value came from 'up'
                i = i - 1;                  // move up
            } else {                        // value came from 'left'
                j = j - 1;                  // move left
            }
        }
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i];
    }
    return 0;
}