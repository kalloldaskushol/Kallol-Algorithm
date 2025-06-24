// Selection Sort
#include <bits/stdc++.h>
using namespace std;

void PrintTheArray(int arr[], int n) { //Function to print the array
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " "; // print space only if the i is greater than 0
    cout << arr[i];
  }
  cout << endl;
}

void SelectionSortFunc(int arr[], int n) {
  int flag = 0; // it will track the count of swaps
  for (int i = 0; i < (n - 1); i++) { // The loop is to select all the elements of the array
    int mini = i; // This will store the index of the smallest value, at the case we assume that the smallest value is i
    for (int j = i + 1; j < n; j++) { // j loop is to compare the rest values with the mini
      if (arr[j] < arr[mini]) { // if we found any value of j which is less then our current mini then we will change the mini value to the lowest value which is j.
        mini = j;
      }
    }
    if (i != mini) { // now it is time to put the lowest value to the perticular index. If the upper if statement is true at any point then after the loop is terminated, the value of mini will be changed from i to j(which would be the lowest value of array)
        // if the i is equal to mini that we can say that the index holds the correct value, no swaps needed
        // but if i is not equal to mini then the i doesnt holds the correct value we have to swap the mini value to the i-th index 
      flag++;  
      swap(arr[i], arr[mini]);
    }
  }

  PrintTheArray(arr, n); // Print the array
  cout << flag << endl; // print the no of swaps
}

int main() {
  int n;
  cin >> n;  //take the size of the array
  int arr[n]; // initialize the array of n size 

  for (int i = 0; i < n; i++) {
    cin >> arr[i]; // take the array input
  }

  SelectionSortFunc(arr, n); // call sorting

  return 0;
}