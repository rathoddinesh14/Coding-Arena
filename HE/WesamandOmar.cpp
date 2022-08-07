// https://www.hackerearth.com/problem/algorithm/wesam-and-omar-e927dd23/?source=list_view

#include <iostream>
using namespace std;

bool NextMove(int i, int j, const char s[]) {
    if (s[3*i+j] == '*') {
        return false;
    }

    if (i == 2 && j == 2) {
        return true;
    }
    else {
        bool check1 = false;
        bool check2 = false;
        bool check3 = false;
        if ((3*i + j + 1) < 9 && s[3*i + j + 1] != '*') {
            check1 = NextMove(i, j+1, s);
        }
        if ((3*(i+1) + j) < 9 && s[3*(i+1) + j] != '*') {
            check2 = NextMove(i+1, j, s);
        }
        if ((3*(i+1) + j + 1) < 9 && s[3*(i+1) + j + 1] != '*') {
            check3 = NextMove(i+1, j+1, s);
        }
        return check1 || check2 || check3;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        char s[9];
        for (int i = 0; i < 9; i++) {
            cin >> s[i];
        }

        if (NextMove(0, 0, s)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
