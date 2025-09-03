#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {

	int coins[] = {1, 5, 10, 25, 50}; // numbs of coins we have
	vector<long int> dp_coin(10001, 0); // it will make a vector of size 10001 initialized to 0

	dp_coin[0] = 1; // Base case: one way to make 0

	for (int i = 0; i < 5; i++) { // Iterate through each coin
		for (int j = coins[i]; j <= 10000; j++) { // Iterate through all amounts from coin value to 10000
			dp_coin[j] += dp_coin[j - coins[i]];
		}
	}

	int n; // Amount to make change for
	while( cin >> n){ // Read the amount
		cout << dp_coin[n] << endl; // Output the number of ways to make change for that amount
	}

	return 0;
}