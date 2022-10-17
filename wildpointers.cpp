/**
 * @brief Wild pointers are pointers that point to memory that has been freed or
 * memory that has never been allocated.
 */

#include <iostream>

using namespace std;

int main() {
    int *p; // Wild pointer

    *p = 10;    // this corrupts the unknown memory location. This should be
                // avoided.
}

// Mac Output : [1]    6082 bus error  ./a.out