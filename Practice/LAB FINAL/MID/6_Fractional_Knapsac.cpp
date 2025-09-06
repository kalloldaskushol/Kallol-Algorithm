#include <bits/stdc++.h>
using namespace std;

struct knap{
	int obj;
	double pbyw;
};

bool compare_pbyw(knap n1, knap n2){
	return n1.pbyw > n2.pbyw;
}

int main(){

	int n, m;
	cin >> n >> m;
	int profit[n], weight[n];

	for(int i = 0; i < n; i++){
		cin >> profit[i];
	}
	for(int i = 0; i < n; i++){
		cin >> weight[i];
	}

	knap sack[n];
	for(int i = 0; i < n; i++){
		sack[i].obj = i;
		sack[i].pbyw = double(profit[i]) / double(weight[i]);
	}

	sort(sack, sack+n, compare_pbyw);

	double X[n];
	memset(X, 0.0, sizeof(X));

	int RW = m;
	int i = 0;
	while(RW > 0){
		
		if(RW >= weight[sack[i].obj]){
			X[sack[i].obj] = 1;
			RW -= weight[sack[i].obj];
			i++;
		} else {
			X[sack[i].obj] = double(RW) / double(weight[sack[i].obj]);
			RW = 0;
		}
	}

	for(int i = 0; i < n; i++){
		cout << X[i] << " ";
	}
	cout << endl;

	double maxProfit = 0;
	for(int i = 0; i<n; i++){
		maxProfit += X[i] * profit[i];
	}
	cout << maxProfit;

	return 0;
}