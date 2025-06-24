// Bubble Sort
#include <bits/stdc++.h>
using namespace std;

int flag = 0; // a variable which will track the comparision count

void PrintTheArray(int n, int arr[]) { // print the array
  for (int i = 0; i < n; i++) { 
    if (i > 0) cout << " "; // print space if the i is greater than 0
    cout << arr[i];
  }
  cout << endl;
}

void BubbleSortFunc(int n, int arr[]) { // Bubble Sort Function
  for (int i = 0; i < n; i++) { // to get all the elements in array 
    for (int j = 0; j < (n - i - 1); j++) { // to compare all the elements with each other
      if (arr[j] > arr[j+1]) { // if the jth element is greater then j+1 th element then push the j th element to j+1 th index
        flag++; // update the comparision count
        swap(arr[j], arr[j+1]);
      }
    } // after 1 iteration the largest value will be moved to the last idx
  }
}

int main() {
  int n; 
  cin >> n; // get the size
  int arr[n]; // make the array with that size

  for (int i = 0; i < n; i++) {
    cin >> arr[i]; // array element input
  }

  BubbleSortFunc(n, arr); // function call to sort the array
  PrintTheArray(n, arr); // to print the array
  cout << flag << endl; // to print the flag
  return 0;
}