#include <bits/stdc++.h>
using namespace std;

void CountingSortFunct(int arr[], int brr[], int n) {
  
  int max_value = arr[0]; // to get the maximum value so that we can get the range of the sorted array.
  
  for (int i = 0; i < n; i++) { // this loop will calculate the maximum element value of the given array 
    if (arr[i] > max_value) max_value = arr[i]; // if the maximum element found store it into the max_value
  }
  
  // initialize a array that will be sized of (max_value+1). At first we will initalize all the value of the array with 0
  int count[max_value + 1] = {0}; 

  for (int i = 0; i < n; i++) {
    count[ arr[i] ]++; // to calculate the frequency of the given array, if we find the a value we will increment the value of that perticular index. like we found element value 2 in the given array, at the case we will increment the index 2 value of the count array
  }

  // Now we have to calculate the sum of the i_th & (i-1)_th value of the count array so that we can get the actual position of the sorted arrays element.
  // the loop will be started from 1 to max_value, as if we start from 0 the loop will try to calculate -1th idx
  for(int i = 1; i<=max_value; i++){
    count[i] = count[i] + count[i-1]; // this will calculate the value of i & i-1th element and store it into the count[i]
  }

  // now our work is to locate the array element and store it at its sorted position
  // arr[i] will be the tagret element which we want to put it into its sorted positon.
  // we will put the value of arr[i] into the sorted array brr. to get the sorted position, we'll decremented count value of that i_th index located into count => the decrimented value of the count will be the correct position of arr[i].

  for (int i = (n - 1); i >= 0; i--) { // we will run the array from the last index so that the prgm works stable.
    brr[--count[arr[i]]] = arr[i]; // this is to input the value of arr[i] to the brr at the position which is mainly decremented count value of arr[i]
  }

}
int main() {
  int n;
  cin >> n; // take the size from the user
  int arr[n]; // make array
  int brr[n]; // sorted array will store in here
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  CountingSortFunct(arr, brr, n); // calling the counting sort function
  for (int i = 0; i < n; i++) { // printing the output
    if(i>0) cout << " ";
    cout << brr[i];
  }
  cout << endl;

  return 0;
}