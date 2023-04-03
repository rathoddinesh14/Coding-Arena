#include <iostream>
#include <vector>
#include <unordered_map>
// time
#include <chrono>
// random
#include <cstdlib>
using namespace std;

/**
 * @brief brute force
 * Time complexity: O(n^3)
 * 
 * @param arr 
 * @param k 
 * @return int 
 */
int countSubArray(vector<int> &arr, int k) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum == k) {
                count++;
            }
        }
    }
    return count;
}

/**
 * @brief slightly optimized
 * Time complexity: O(n^2)
 * 
 * @param arr 
 * @param k 
 * @return int 
 */
int countSubArray_v2(vector<int> &arr, int k) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == k) {
                count++;
            }
        }
    }
    return count;
}

/**
 * @brief optimized
 * Time complexity: O(n * log(n))
 * Log(n) for finding the sum in the map
 * 
 * @param arr 
 * @param k 
 * @return int 
 */
int countSubArray_opt(vector<int> &arr, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, int> map;
    map[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        count += map[sum - k];
        map[sum]++;
    }

    return count;
}

int main() {

    // result
    // vector<int> arr = {10, 2, -2, -20, 10};
        // 3
        // Time taken by function: 37 microseconds
        // 3
        // Time taken by function: 3 microseconds
        // 3
        // Time taken by function: 29 microseconds

    // random array
    vector<int> arr;
    for (int i = 0; i < 1000; i++) {
        arr.push_back(rand() % 100);
    }
    // 18
    // Time taken by function: 597577 microseconds
    // 18
    // Time taken by function: 3444 microseconds
    // 18
    // Time taken by function: 1461 microseconds

    int k = 10;

    // time
    auto start = chrono::high_resolution_clock::now();
    cout << countSubArray(arr, k) << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    cout << countSubArray_v2(arr, k) << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    cout << countSubArray_opt(arr, k) << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}