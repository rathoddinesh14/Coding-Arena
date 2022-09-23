// https://www.geeksforgeeks.org/find-the-missing-number/


#include <iostream>
#include <vector>

using namespace std;


/**
 * @brief Get the Missing Num object
 * time complexity: O(n), where n is the size of the array
 * @param arr 
 * @return int 
 */
int getMissingNum(vector<int> arr) {

    int n = arr.size();
    int total = (n + 1) * (n + 2) / 2;

    for (int i = 0; i < n; i++)
        total -= arr[i];

    return total;
}


/**
 * @brief Get the Missing Num object - avoids overflow
 * time complexity: O(n), where n is the size of the array
 * @param arr 
 * @return int 
 */
int getMissingNum_Overflow(vector<int> arr) {

    int n = arr.size();
    int total = 1;
    for (int i = 2; i < n+2; i++) {
        total += i;
        total -= arr[i-2];
    }

    return total;
}


/**
 * @brief Get the Missing Num object - XOR
 * time complexity: O(n), where n is the size of the array
 * @param arr 
 * @return int 
 */
int getMissingNum_XOR(vector<int> arr) {

    int n = arr.size();
    int x1 = arr[0];
    int x2 = 1;

    for (int i = 1; i < n; i++)
        x1 = x1 ^ arr[i];

    for (int i = 2; i < n+2; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}

int main() {

    vector<int> arr = { 1, 2, 4, 5, 6 };
    cout << getMissingNum(arr) << endl;
    cout << getMissingNum_Overflow(arr) << endl;
    cout << getMissingNum_XOR(arr) << endl;

    arr.clear();

    arr = { 1, 2, 3, 5 };
    cout << getMissingNum(arr) << endl;
    cout << getMissingNum_Overflow(arr) << endl;
    cout << getMissingNum_XOR(arr) << endl;

    arr.clear();

    arr = { 1, 2, 3, 4, 5, 6, 8, 9, 10 };
    cout << getMissingNum(arr) << endl;
    cout << getMissingNum_Overflow(arr) << endl;
    cout << getMissingNum_XOR(arr) << endl;

    return 0;
}