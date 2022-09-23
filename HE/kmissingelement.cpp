// https://www.geeksforgeeks.org/k-th-missing-element-in-an-unsorted-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * @brief find the kth missing element in an unsorted array
 * Time complexity: O(n), where n is the size of the array
 * 
 * @param arr 
 * @param k 
 * @return int 
 */
int kthmisselement(vector<int> arr, int k) {

    // min and max element in the array
    int minEle = *min_element(arr.begin(), arr.end());
    int maxEle = *max_element(arr.begin(), arr.end());

    int count = 0;

    // iterate from min to max element
    for (int i = minEle; i <= maxEle; i++) {

        // if i is not present in the array
        // then increment count
        if (find(arr.begin(), arr.end(), i) == arr.end())
            count++;

        // if count is equal to k
        // then return i
        if (count == k)
            return i;
        else if (count > k)
            return -1;
    }

    return -1;
}


int main() {

    vector<int> arr = { 2, 10, 9, 4 };

    int k = 9;

    cout << kthmisselement(arr, k) << endl;

    return 0;
}