#include <bits/stdc++.h>
using namespace std;

// stack size = n, bcz base call doesnt stores
// we can't get 100 bcz of space.
int FiboMemo(int n, int F[]){
    // Base Case
    if(n<=1){
        F[n] = n;
        return n;
    }

    // if value -1 work
    if(F[n] == -1){
        F[n] = FiboMemo(n-1, F) + FiboMemo(n-2, F); // stack size is defined by the lowest value.
    }

    // if its not -1 and not base case return F[n]
    return F[n];
}

int main(){

    int n;
    cin >> n;
    int F[n+1]; // why
    memset(F, -1, sizeof(F));

    int result = FiboMemo(n, F);
    cout << result << endl;

    return 0;
}