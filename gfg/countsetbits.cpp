#include <iostream>
#include <cassert>
using namespace std;

/**
 * @brief Let's take an example to understand this better. 
 * Suppose we call countSetBits(10). Here's what happens:

    The largest power of 2 less than or equal to 10 is 2^3=8, so p=3.
    The number of set bits in the range from 0 to 7 is 3 * 2^(3-1) = 12.
    The number of set bits in the range from 8 to 10 is (10 - 8 + 1) + countSetBits(2) = 3 + countSetBits(2).
    To calculate countSetBits(2), we repeat the above steps with N=2.
    The largest power of 2 less than or equal to 2 is
 */

int getLargestPowerOf2(int n) {
    assert(n >= 0);
    int p = 0;
    while ((1 << p) <= n) {
        p++;
    }
    return p - 1;
}

/**
 * @brief Count set bits in all numbers from 1 to N
 * Time Complexity: O(logN)
 * 
 * @param N 
 * @return int 
 */
int countSetBits(int N) {
    int count = 0;
    
    // base case
    if (N == 0) return 0;
    else {
        int p = getLargestPowerOf2(N);
        count += p * (1 << (p - 1));
        count += (N - (1 << p) + 1) + countSetBits(N - (1 << p));
    }

    return count;
}


int main() {
    int n = 10;
    cout << countSetBits(n) << endl;
    return 0;
}