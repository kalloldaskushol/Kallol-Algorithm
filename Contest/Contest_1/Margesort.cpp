// MergeSort
#include <bits/stdc++.h>
using namespace std;
int flag = 0; //flag variable which is initialized at the outside of main so that it could be a golbal variable

void PrintTheArray(int n, int arr[]) { // to print the array
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " "; // prints space when i is greater than 0

    cout << arr[i];
  }
  cout << endl;
}

void MergeingFunc(int L, int mid, int H, int arr[]) { // making merge function
  int m = mid - L + 1; // left sub array size
  int n = H - mid; // right sub array size
  int A[m], B[n]; // making temp array for comparing

  for (int i = 0; i < m; i++) { // giving values of A
    A[i] = arr[L + i]; // the left sub array will start from L
  }
  for (int j = 0; j < n; j++) { // giving values to B
    B[j] = arr[mid + 1 + j]; // the right sub array will start from (mid+1)
  }

  int i = 0, j = 0, k = L; // K = L so that the sorted array in not overwrited
  while (i < m && j < n) { // merging 
    if (A[i] < B[j]) { // if the value of A[i] is less than the B[j] means that the lowest element stands in A[i]
      arr[k] = A[i]; // to give the correct value to the arr[k]
      i++;
      k++;

      flag++; // update the value of comparision
    } else {
      arr[k] = B[j]; // if it is false then B[j] is the lowest value. Give the value to arr[k]
      j++;
      k++;

      flag++; // update the value of comparision
    }
  }

  for (; i < m; i++) { //Copy rest elements from A
    arr[k] = A[i];
    k++;
    flag++; // update the value of comparision
  }
  for (; j < n; j++) { //Copy rest elements from B
    arr[k] = B[j];
    k++;
    flag++; // update the value of comparision
  }
}

void MargeSortFunc(int L, int H, int arr[]) { // This is the margesort function
  if (L < H) { // if low is equal to high means i got the index value
    int mid = (L + H) / 2; // it will get the mid

    MargeSortFunc(L, mid, arr); // calling the sort for left sub array
    MargeSortFunc(mid + 1, H, arr); // calling the sort for right sub array
    MergeingFunc(L, mid, H, arr); // merging function will merge the values in a sorted way
  }
}
int main() {
  int n;
  cin >> n; // The size of input array
  int arr[n]; // initialize the array with n size
  for (int i = 0; i < n; i++) {
    cin >> arr[i]; // // input taking
  }
  MargeSortFunc(0, n - 1, arr); // calling merge sort
  PrintTheArray(n, arr); // printing the array
  cout << flag << endl; // printing the value of flag
  return 0;
}