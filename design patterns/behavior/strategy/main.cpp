// main.cpp
#include <iostream>
#include <vector>
#include "Context.h"
#include "BubbleSort.h"
#include "QuickSort.h"

void printData(const std::vector<int>& data) {
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};

    Context context;

    std::cout << "Original data: ";
    printData(data);

    // Using Bubble Sort
    context.setStrategy(new BubbleSort());
    context.executeStrategy(data);
    std::cout << "Sorted using BubbleSort: ";
    printData(data);

    data = {5, 2, 9, 1, 5, 6}; // Reset data

    // Using Quick Sort
    context.setStrategy(new QuickSort());
    context.executeStrategy(data);
    std::cout << "Sorted using QuickSort: ";
    printData(data);

    return 0;
}
