#include <iostream>
#include <memory>

// Forward declaration
class Context;

// State Interface
class State {
public:
    virtual ~State() = default;
    virtual void handle(Context& context) = 0;
};

// Context Class
class Context {
private:
    std::unique_ptr<State> state;

public:
    Context(std::unique_ptr<State> initialState) : state(std::move(initialState)) {}

    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }

    void request() {
        state->handle(*this);
    }
};

// Concrete States
class ClosedState : public State {
public:
    void handle(Context& context) override;
};

class OpenState : public State {
public:
    void handle(Context& context) override;
};

class ListeningState : public State {
public:
    void handle(Context& context) override;
};

// Implementations of Concrete State Methods
void ClosedState::handle(Context& context) {
    std::cout << "Currently in Closed state. Opening connection..." << std::endl;
    context.setState(std::unique_ptr<OpenState>(new OpenState()));
}

void OpenState::handle(Context& context) {
    std::cout << "Currently in Open state. Listening for data..." << std::endl;
    context.setState(std::unique_ptr<ListeningState>(new ListeningState()));
}

void ListeningState::handle(Context& context) {
    std::cout << "Currently in Listening state. Closing connection..." << std::endl;
    context.setState(std::unique_ptr<ClosedState>(new ClosedState()));
}

// Main Function
int main() {
    // Initialize context with an initial state
    Context context(std::unique_ptr<ClosedState>(new ClosedState()));

    // Simulate requests
    context.request(); // Transition from Closed to Open
    context.request(); // Transition from Open to Listening
    context.request(); // Transition from Listening to Closed

    return 0;
}
