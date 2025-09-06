#include <bits/stdc++.h>
using namespace std;

void insertion_Sort(int n, int arr[]){

	for(int i = 0; i < n; i++){ // to iterrate over the array
		int key = arr[i];
		int comp = i - 1;
		while(comp >= 0 && arr[comp] > key){
			swap(arr[comp], arr[comp + 1]);
			comp--;
		}
		arr[comp + 1] = key;
	}
}

int main(){

	int n;
	cin >> n;
	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	insertion_Sort(n, arr);

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}