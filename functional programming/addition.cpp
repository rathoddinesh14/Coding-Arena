#include <iostream>
#include <functional>

using namespace std;

// lambda function
function<int(int, int)> l_add = [](int a, int b) { return a + b; };

// higher order function
function<int(int)> add(int x) {
    return [x](int y) {
        return x + y;
    };
}

int main() {

    auto add2 = add(2);
    cout << add2(3) << endl;

    cout << add(3)(4) << endl;

    cout << l_add(3, 4) << endl;
    return 0;
}