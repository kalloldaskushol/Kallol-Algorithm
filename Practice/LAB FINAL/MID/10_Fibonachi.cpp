#include <bits/stdc++.h>
using namespace std;

int fibo(int n, int F[]){

	for(int i = 2; i <= n; i++){
		F[i] = F[i-1] + F[i-2];
	}
	return F[n];
}

int main(){

	int n;
	cin >> n;
	int F[n + 1];
	
	F[0] = 0;
	F[1] = 1;

	int result = fibo(n, F);
	cout << result;

	return 0;
}