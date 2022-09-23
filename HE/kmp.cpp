// https://www.youtube.com/watch?v=GTJr8OvyEVQ
// https://github.com/mission-peace/interview/blob/master/src/com/interview/string/SubstringSearch.java


#include <iostream>
#include <vector>

using namespace std;


/**
 * @brief Get the prefix suffix vector
 * psv[i] = length of longest proper prefix of pattern[0..i] which is also a suffix of pattern[0..i]
 * @param pattern string
 * @return vector<int> 
 */
vector<int> get_psv(string pattern) {
    int m = pattern.size();
    vector<int> psv(m, 0);
    int i = 1;
    int j = 0;
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            psv[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = psv[j - 1];
            } else {
                psv[i] = 0;
                i++;
            }
        }
    }
    return psv;
}


/**
 * @brief Knuh Morris Pratt algorithm
 * Naive algorithm is O(mn) where m is length of text and n is length of pattern
 * KMP algorithm is O(m + n) where m is length of text and n is length of pattern
 * @param text string
 * @param pattern string
 * @return true if pattern is found in text
 */
bool KMP(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> psv = get_psv(pattern);
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = psv[j - 1];
            } else {
                i++;
            }
        }
    }
    if (j == m) {
        return true;
    }
    return false;
}


int main() {

    string text = "abcxabcdabcdabcy";
    string pattern = "abcdabcy";

    if (KMP(text, pattern)) {
        cout << "Pattern found" << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}