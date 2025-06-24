//Insertion Sort
#include <bits/stdc++.h>
using namespace std;

void printTheArray(int arr[], int n) { // this loop is for printing the array
  for (int i = 0; i < n; i++) {
    if(i>0){
      cout << " "; // to print the space only if the i is greater than 0
    } 
    cout << arr[i];
  }
  cout << endl;
}

void insertionSortFunc(int arr[], int n) {
  for (int i = 0; i < n; i++) { //to get all the indices
    int pick = arr[i]; //pick the perticular index
    int j = i - 1; // j will be initialized with the previous value of i & it will be used to compare elements with i.
    while (j >= 0 && arr[j] > pick) { // the loop will be working if the value of j is greater than 0(bcz, if the array starts with 0 index)..
      // if the j-th element of the array is greater than the pick element
      swap(arr[j + 1], arr[j]); // if the loop runs means both the condition are true. than lets swap the j+1 th element with jth element
      j--; // decrement the value of j so that the rest values can be compared
    }
    arr[j + 1] = pick; // after the loop ends we got the perfect index to insert the pick, bcz from the 0 to j-th index every element is lesser than the pick element and after j all the elememnts are larger. So finally j+1 is the correct index for my picked element

    printTheArray(arr, n); //to print the array after every iteration
  }
}

int main() {
  int n;
  cin >> n; //take the size of the array

  int arr[n]; // initialize the array with the n size.

  for (int i = 0; i < n; i++) { // take the array innput
    cin >> arr[i];
  }

  insertionSortFunc(arr, n); // call the insertion function

  return 0;
}