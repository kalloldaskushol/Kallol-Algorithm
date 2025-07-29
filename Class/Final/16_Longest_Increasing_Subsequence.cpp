// ideone.com/8r1vQg

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

    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(list[j] < list[i]){
                LIS[i] = max(LIS[i], 1+LIS[j]);
                
                if(LIS[i] == 1+LIS[j]){
                    Tracker[i] = j;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout << LIS[i] << " ";
    }
    cout << endl;
    

    // not always at last

    int mx = INT_MIN;
    int maxidx;
    for(int i = 0; i<n; i++){
        if(mx < LIS[i]) {
            mx=LIS[i];
            maxidx = i;
    }
}
    cout << "LIS Length = " << mx << endl;
    for(int i = 0; i<n; i++){
        cout << Tracker[i] << " ";
    }
    cout << endl;

    // Sequence 
    vector<int> ans;
    for(int i = maxidx; i>=0; ){
        ans.push_back(list[i]);
        i = Tracker[i];
    }

    for(int i = ans.size()-1 ; i>= 0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}