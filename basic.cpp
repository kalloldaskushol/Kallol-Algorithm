#include<bits/stdc++.h>
using namespace std;

int main()
{
    //int x = 5;
    //printf("%d %d %d %d", x++, ++x, x--, --x ); // RIGHT TO LEFT
    //cout << x++ << " " << ++x << " " << x-- << " " << --x << endl; // LEFT TO RIGHT

    /*Array*/
    /*
    int n; // declare the size of the array
    cin>>n; // taking input of size n

    int arr[n]; // declare the n size array
    for(int i=0; i<n;i++){
        cin >> arr[i]; // taking the array as input using the loop
    }
    */
/*Range of int, char, float, double
    int x, y;
    x = INT_MAX;
    y = INT_MIN;
    cout << "Lowest " << y << endl;
    cout << "Highest " << x << endl;
*/
/*2D Array*/
    int n, m; //declare the 2 dimension
    cin>>n>>m; // taking input the dimensions
    int A[n][m]; // declare nxm array
    for(int i = 0; i < n; i++) /// row // taking 2d array input using two nested for loop
    {
        for(int j = 0; j < n; j++) /// column
        {
            cin>>A[i][j];
        }
    }
    return 0;
}
