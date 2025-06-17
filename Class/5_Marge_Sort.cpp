// ideone.com/NWejpn
#include <bits/stdc++.h>
using namespace std;
// Recursion
void Merging(int L, int mid, int H, int arr[])
{
    int m = mid - L + 1;
    int n = H - mid;
    int A[m], B[n];

    for (int i = 0; i < m; i++)
    {
        A[i] = arr[L + i]; // A starts from L
    }

    for (int j = 0; j < n; j++)
    {
        B[j] = arr[mid + 1 + j]; // B starts from (mid+1)
    }

    int i = 0, j = 0, k = L; // K=L new array starts from L
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            arr[k] = A[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = B[j];
            j++;
            k++;
        }
    }

    for (; i < m; i++)
    {
        arr[k] = A[i];
        k++;
    }
    for (; j < n; j++)
    {
        arr[k] = B[j];
        k++;
    }
}
void MergeSort(int L, int H, int arr[])
{
    if (L < H)
    {
        int mid = (L + H) / 2;
        MergeSort(L, mid, arr);
        MergeSort(mid + 1, H, arr); // O(log n)
        Merging(L, mid, H, arr);    // O(n)
        // Total T.C O(nlogn)
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
    MergeSort(0, n - 1, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}