#include <bits/stdc++.h>
using namespace std;

void PrintTheArray(int n, int arr[]) {
  for (int i = 0; i < n; i++) {
    // if(i>0) cout << " ";
    cout << arr[i] << endl;
  }
}

int PartitionFunc(int p, int r, int arr[]) {
  int x = arr[r];
  int i = p - 1;

  for (int j = p; j < r; j++) {
    arr[j] = x;
    i++;
    swap(arr[i], arr[j]);
  }
  swap(arr[i + 1], arr[r]);
  return (i + 1);
}
void quickSortFunc(int L, int H, int arr[]) {
  if (L < H) {
  int part = PartitionFunc(L, H, arr);
        quickSortFunc(L, part-1, arr);
        quickSortFunc(part+1, H, arr);
    }
}
int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }
    quickSortFunc(0, n-1, arr);
    PrintTheArray(n, arr);

    return 0;
}