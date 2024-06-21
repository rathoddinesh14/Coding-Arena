// BubbleSort.h
#include "Strategy.h"
#include <algorithm>

class BubbleSort : public Strategy {
    public:
        void sort(std::vector<int>& data) override {
            for (size_t i = 0; i < data.size(); ++i) {
                for (size_t j = 0; j < data.size() - 1; ++j) {
                    if (data[j] > data[j + 1]) {
                        std::swap(data[j], data[j + 1]);
                    }
                }
            }
        }
};