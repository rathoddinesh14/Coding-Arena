/**
 * @brief This program is used to test the memory leak.
 * 
 */

#include <iostream>
#include <string>

using namespace std;

void memoryLeak() {
    int *p = new int[100];
    cout << "memoryLeak" << endl;
}

void FixMemoryLeak() {
    int *p = new int[100];
    delete [] p;
    cout << "FixMemoryLeak" << endl;
}


int main() {

    memoryLeak();
    FixMemoryLeak();

    return 0;
}