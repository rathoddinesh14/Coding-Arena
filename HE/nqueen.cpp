// https://www.hackerearth.com/problem/algorithm/n-queensrecursion-tutorial/?source=list_view

#include <iostream>
using namespace std;

int board[10][10] = {0};

int n;

bool isSafe(int r, int c) {

    for (int i = 0; i < r; i++) {
        if (board[i][c] == 1) return false;
    }

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

bool nqueen(int r) {
    if (r >= n) return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(r, i)) {
            board[r][i] = 1;

            if (nqueen(r + 1)) {
                return true;
            }
            
            board[r][i] = 0;    // backtrack
        }
    }
    return false;
}

int main() {
    cin >> n;
    // n = 4;

    if (nqueen(0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Not possible" << endl;
    }

    return 0;
}