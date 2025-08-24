// https://ideone.com/8r1vQg
/*
memset(arr, 0, sizeof(arr)) its stored values by byte =>
    00000000-00000000-00000000 which is 0
    00000000-00000000-00000001 which is 1
but memset makes it 00000001-00000001-00000001 if it is called by memset beacause --> memset stores the value by byte

! we knew Negative number = 1's complement + 1

1s comp
    1  = 00000001
       = 11111110
       =        1
-------------------
       = 11111111 <-- This is -1 in 8-bit binary

so if the memset is called by -1 
    in bytes it becomes --> 11111111-11111111-11111111-11111111 which is -1
! thats why memset can worked perfectly with -1 and 0.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; // Length of the input sequence
    cin >> n;
    int list[n];
    
    for(int i = 0; i<n; i++){
        cin >> list[i];
    }
    int LIS[n], Tracker[n];

    memset(Tracker, -1, sizeof(Tracker)); //! Initially set all elements of tracker to -1

    for(int i = 0; i < n; i++){ //! Initialize LIS values set to 1, as a single digit is also its subsequence
        LIS[i] = 1;
    }

    //! Find the longest increasing subsequence loop
    for(int i = 1; i < n; i++){ // starts from 1 index
        for(int j = 0; j < i; j++){ // starts from 0 index

            if(list[i] > list[j]){ // If the current element is greater than the previous elements
                LIS[i] = max(LIS[i], 1 + LIS[j]);  //! LIS[i] → stores the length of the longest increasing subsequence ending at list[i].

                if(LIS[i] == 1 + LIS[j]){ //if the LIS comes from j then update the tracker to j
                    Tracker[i] = j; //! Tracker[i] → stores the index of the previous element in the longest increasing subsequence ending at list[i].
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout << LIS[i] << " ";
    }
    cout << endl;
    

    // not always at last, so lets find the maximum length
    int maxVal = INT_MIN;
    int maxidx; // maxidx → index where LIS ends.
    for(int i = 0; i<n; i++){
        if(LIS[i] > maxVal) {
            maxVal = LIS[i];
            maxidx = i;
        }
    }

    cout << "LIS Length = " << maxVal << endl;

    // Print the Tracker array --> Helps visualize the previous index for each element in LIS.
    for(int i = 0; i<n; i++){
        cout << Tracker[i] << " ";
    }
    cout << endl;

    // Find the Sequence 
    vector<int> ans;
    
    for(int i = maxidx; i>=0; ){

        ans.push_back(list[i]); // put the i-th element into the answer
        i = Tracker[i];
    }

    // Print the Sequence reverse
    for(int i = ans.size()-1 ; i>= 0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}