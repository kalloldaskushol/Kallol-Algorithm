#include <bits/stdc++.h>
using namespace std;



void Merging(int L, int mid, int H, int arr[]){
	int m = mid - L + 1;
	int n = H - mid;
	int A[m], B[n];
	
	// fill time
	for(int i = 0; i < m; i++){
		A[i] = arr[L + i];
	}
	for(int j = 0; j < n; j++){
		B[j] = arr[mid + 1 + j];
	}
	
	// now lets merge
	int i = 0, j = 0, k = L;
	
	while(i < m && j < n){
		if(A[i] < B[j]){
			arr[k] = A[i]; i++; k++;
		} else {
			arr[k] = B[j]; j++; k++;
		}
	}
	
	for(	; i < m; i++){
		arr[k] = A[i]; 
		k++;
	}
	for(	; j < n; j++) {
		arr[k] = B[j];
		k++;
	}
}

void Merge_Sort(int L, int H, int arr[]){
	if(L < H){
		int mid = (H+L)/2;
		Merge_Sort(L, mid, arr);
		Merge_Sort(mid+1, H, arr);
		Merging(L, mid, H, arr);
	}
}
int main(){
	
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}

	Merge_Sort(0, n-1, arr);

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}