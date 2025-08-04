// ⭐⭐⭐⭐⭐ LAB FINAL
// https://ideone.com/X2Qhgv
#include <bits/stdc++.h>
using namespace std;

struct knap { // to make a custom structure, So that we can store the product by weight with the fixed object
  
    int object; // obj number
    double p_by_w; // product by weight -> double cz it can be a decimal number.
};

// bool compare_p_by_w(knap n1, knap n2) {
//     if (n1.p_by_w > n2.p_by_w)  return true;
//     else  return false;
// }

bool compare_p_by_w(knap n1, knap n2){
  return n1.p_by_w > n2.p_by_w;
}

int main() {
  int n, m;
  // n = number of object
  // m total weight
  cin >> n >> m;

  int profit[n]; // making an array to store the profit of n objects
  int weights[n]; // making an array to store the weights of n objects

  for (int i = 0; i < n; i++) {
    cin >> profit[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }

  knap sack[n]; // making the structure array -> so that we can store the object with their coresponding (product / weight)
  
  for (int i = 0; i < n; i++) { // O(n) for p by w

    sack[i].object = i; // the number of iteration = number of that object
    sack[i].p_by_w = double(profit[i]) / double(weights[i]); // calculating their coresponding profit by weight
  }

  sort(sack, sack + n, compare_p_by_w); // sort function -> it will sort the sack structure by the profit by weight
                                        //!   sort funtion will take O(nlogn) thats the total comp ⭐
             
  int RW = m; // initally the remaining weight is the total weight of the full bag.
  
  double X[n]; // ans array it will tell us how much weight we will carry.
  memset(X, 0.0, sizeof(X));

  // now the sack is sorted and the highest P by W is at the first.
  int i = 0;
  while (RW > 0) { // keep adding until the bag is empty

    if (RW >= weights[sack[i].object]) { // if the remaining weight is equal or greater than -> the i_th obj weight 
      X[sack[i].object] = 1; // then take the full of it.
      RW = RW - weights[sack[i].object]; // change the remaining weight. 
      i++; // update the i.

    } else { // means that we cant take the rest element full due to the shortage of size.
      X[sack[i].object] = double(RW) / double(weights[sack[i].object]); // we will take the fractional value of the highest p by w object.
      RW = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << X[i] << " ";
  }
  cout << endl;

  double maxprofit = 0; // to calculate the max profit.
  for (int i = 0; i < n; i++) {
    maxprofit = maxprofit + (X[i] * double(profit[i])); // max profit is equal to max profit + the size we took with the multiplication of the profit.
  }
  cout << maxprofit << endl;

  return 0;
}