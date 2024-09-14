// min stack ADT which gives min element in O(1) time
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s;
    int minEle;

public:
    void push(int x) {
        if (s.size() == 0) {
            s.push(x);
            minEle = x;
        } else {
            if (x < minEle) {
                s.push(2 * x - minEle);
                minEle = x;
            } else {
                s.push(x);
            }
        }
    }

    void pop() {
        if (!s.empty()) {
            if (s.top() < minEle) {
                minEle = 2 * minEle - s.top();
            }
            s.pop();
        }
    }

    int top() {
        if (!s.empty()) {
            if (s.top() < minEle) {
                return minEle;
            }
            return s.top();
        }
        return -1; // or throw an exception
    }

    int getMin() {
        if (!s.empty()) {
            return minEle;
        }
        return -1; // or throw an exception
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    cout << minStack.top();    // return 0
    minStack.getMin(); // return -2
    return 0;
}