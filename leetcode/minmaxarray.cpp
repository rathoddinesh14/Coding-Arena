#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * @brief this is a lee code problem (minimize maximum of array)
 * Time complexity: O(n)
 * Allowed operation:
 * A[i] += 1
 * A[i-1] -= 1
 * 
 * @param nums - non negative array
 * @return int - minimized maximum of array
 */
int minmaxArray(vector<int> &nums) {
    int res = nums[0];
    double avgSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        avgSum += nums[i];
        avgSum  = ceil(avgSum / (i + 1));
        res = max(res, (int)avgSum);
    }

    return res;
}


int main() {
    // non negative array
    vector<int> nums = {1, 12, 5, 111, 200};
    cout << minmaxArray(nums) << endl;

    nums = {3, 7, 1, 6};
    cout << minmaxArray(nums) << endl;
    return 0;
}