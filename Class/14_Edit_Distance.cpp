// ideone.com/vp37K9

#include <bits/stdc++.h>
using namespace std;

int main(){

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int m = s1.size(); // s1 to col -> s1 need to be changed
    int n = s2.size(); 

    int edit[n+1][m+1];

    for(int i = 0; i<n+1; i++){ // insertion up->down 
        edit[i][0] = i;
    }
    for(int j = 0; j<m+1; j++){ // delete left -> right
        edit[0][j] = j;
    }

    
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(s2[i-1] == s1[j-1]){ // matched so the value comes directly from the diagonal
                                    // s2 in row so we use s1[j-1];
                                    // s1 in col so we use s1[i-1];   
                edit[i][j] = edit[i-1][j-1];
            } else {
                edit[i][j] = 1 + min({edit[i-1][j], edit[i][j-1], edit[i-1][j-1]});
            }
        }
    }

    
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            cout << edit[i][j] << " ";
        }
        cout << endl;
    }

    int i = n, j = m;
    while(i>0){
        if(s2[i-1] == s1[j-1]){ // matched no operation
            i = i - 1;
            j = j - 1;
        } else {
            if(edit[i][j] == 1 + edit[i-1][j-1]){ // replace
                cout << s1[j-1] << " is replaced to " << s2[i-1] << endl;
                i = i - 1;
                j = j - 1;
            } else if (edit[i][j] == 1 + edit[i-1][j]){ // insert
                cout << s2[i-1] << " is inserted " << endl;
                i = i - 1;

            } else { // delete
                cout << s1[j-1] << " is deleted "<< endl;
                j = j - 1;
            }
        }
    }
    return 0;
}