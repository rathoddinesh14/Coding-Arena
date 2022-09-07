// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// https://www.youtube.com/watch?v=2pnCqUz17cQ

#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

/**
 * @brief recursive solution
 * 
 * @param prices array of prices
 * @param n length of rod
 * @return maximum profit
 */
int cutRod(int price[], int n) {

    // base case
	if (n <= 0) {
        return 0;
    }

    int max_val = numeric_limits<int>::min();

    // Recursively cut the rod in different pieces and compare different
    for (int i = 1; i <= n; i++) {
        max_val = max(max_val, price[i-1] + cutRod(price, n - i));
    }

    return max_val;
}


int main() {
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

	int size = sizeof(arr) / sizeof(arr[0]);
	
    // size should be less than/equal to number of elements in array
    cout << "Maximum Value is " << cutRod(arr, size) << endl;
	return 0;
}
