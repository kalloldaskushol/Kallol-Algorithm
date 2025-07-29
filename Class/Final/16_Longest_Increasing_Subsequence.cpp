/*
memset(arr, 0, sizeof(arr)) its stored values by byte
00000000-00000000-00000000
00000000-00000000-00000001 which is 1
but memset makes it 00000001-00000001-00000001 if it is called by 1 reason is memset stores the value by byte

1s comp
+1 = 00000001
   = 11111110
   =        1
---------------
   = 11111111 which is (-1)

so if the memset is called by -1 
11111111-11111111-11111111-11111111 which is -1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int list[n];
    
    for(int i = 0; i<n; i++){
        cin >> list[i];
    }
    int LIS[n], Tracker[n];

    memset(Tracker, -1, sizeof(Tracker));
    for(int i = 0; i<n; i++){
        LIS[i] = 1;
    }

    

    return 0;
}