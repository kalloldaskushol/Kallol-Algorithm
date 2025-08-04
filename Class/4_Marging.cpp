// ideone.com/qfk0Xt
#include <bits/stdc++.h>
using namespace std;

void marging(int A[], int B[], int C[], int m, int n){

    //! Array A and B must be sorted
    int i = 0, j = 0, k = 0;

    while (i < m && j < n){

        if (A[i] < B[j]){

            C[k] = A[i];
            i++;
            k++;
        }else{

            C[k] = B[j];
            j++;
            k++;
        }
    }
    //! copy rest elements
    for (; i < m; i++){
        C[k] = A[i];
        k++;
    }
    for (; j < n; j++){
        C[k] = B[j];
        k++;
    }
}
int main(){

    int m, n;
    cin >> m >> n;
    int A[m], B[n];
    for (int i = 0; i < m; i++){
        cin >> A[i];
    }

    for (int j = 0; j < n; j++){
        cin >> B[j];
    }
    int C[m + n];

    marging(A, B, C, m, n);

    for (int k = 0; k < (m + n); k++){
        cout << C[k] << " ";
    }
    return 0;
}

/*
3 3
2 8 15
3 5 12
*/