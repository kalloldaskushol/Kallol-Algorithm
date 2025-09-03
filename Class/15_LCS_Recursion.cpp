// ideone.com/WoK1FGq
#include <bits/stdc++.h>
using namespace std;

int n, m;

int LCS(char A[], char B[], int i, int j){
    if(i == n || j == m)    return 0;

    else if(A[i] == B[j])   return 1 + LCS(A, B, i+1, j+1);

    else return max(LCS(A, B, i+1, j), LCS(A, B, i, j+1));
}
int main(){

    cin >> n >> m;
    char A[n], B[m];
    cin >> A >> B;

    int ans = LCS(A, B, 0, 0);

    cout << ans << endl;

    return 0;
}