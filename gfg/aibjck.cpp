#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Count number of subsequences of the form aibjck
 * Time Complexity: O(n)
 * @param s 
 * @return int 
 */
int numSubs(string &s) {
    int ac = 0, bc = 0, cc = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
            // include 'a' (old number of subsequences)
            // exlcude 'a' (old number of subsequences)
            // new subsequence with a (+1)
            ac = 1 + 2 * ac;
        } else if (s[i] == 'b') {
            // include 'b' (old number of subsequences)
            // exlcude 'b' (old number of subsequences)
            bc = ac + 2 * bc;
        } else {
            // include 'c' (old number of subsequences)
            // exlcude 'c' (old number of subsequences)
            cc = bc + 2 * cc;
        }
    }

    return cc;
}


int main() {

    string s;
    s = "abbc";

    // Output: 3
    cout << numSubs(s) << endl;

    s = "abcabc";

    // Output: 7
    cout << numSubs(s) << endl;

    return 0;
}