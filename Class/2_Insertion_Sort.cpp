// ideone.com/zXzLmN
#include <bits/stdc++.h>
using namespace std;
// why it is caalled insertion sort => we are comping then insetting it to the postition.
// what is the worst case of it,
void insertion(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    { // for picking values
        int pick = arr[i];
        int j = i - 1; // comping index

        while (j >= 0 && arr[j] > pick)
        { // comping index must be greater than 0 & comping index value must be greater then pick
            swap(arr[j + 1], arr[j]);
            j--; // to check the previous index again
        }
        arr[j + 1] = pick; // fix the position of every pick
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertion(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}