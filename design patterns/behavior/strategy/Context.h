// Context.h
#include "Strategy.h"

class Context {
public:
    Context(Strategy* strategy = nullptr) : strategy_(strategy) {}

    ~Context() {
        delete strategy_;
    }

    void setStrategy(Strategy* strategy) {
        delete strategy_;
        strategy_ = strategy;
    }

    void executeStrategy(std::vector<int>& data) {
        if (strategy_) {
            strategy_->sort(data);
        }
    }

private:
    Strategy* strategy_;
};
