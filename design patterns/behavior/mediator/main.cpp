#include <iostream>
#include <string>
#include <memory>

// Forward declarations
class Button;
class TextBox;

// Mediator Interface
class Mediator {
public:
    virtual void notify(const std::string& sender, const std::string& event) = 0;
};

// Colleague Interface
class Component {
protected:
    Mediator* mediator;

public:
    Component(Mediator* mediator = nullptr) : mediator(mediator) {}
    void setMediator(Mediator* mediator) {
        this->mediator = mediator;
    }
};

// Concrete Colleague: Button
class Button : public Component {
public:
    using Component::Component;

    void click() {
        std::cout << "Button clicked.\n";
        if (mediator) {
            mediator->notify("Button", "click");
        }
    }
};

// Concrete Colleague: TextBox
class TextBox : public Component {
private:
    std::string text;

public:
    using Component::Component;

    void setText(const std::string& newText) {
        text = newText;
        std::cout << "TextBox text set to: " << text << std::endl;
        if (mediator) {
            mediator->notify("TextBox", "setText");
        }
    }

    const std::string& getText() const {
        return text;
    }
};

// Concrete Mediator: Dialog
class Dialog : public Mediator {
private:
    Button* button;
    TextBox* textBox;

public:
    void setButton(Button* button) {
        this->button = button;
        button->setMediator(this);
    }

    void setTextBox(TextBox* textBox) {
        this->textBox = textBox;
        textBox->setMediator(this);
    }

    void notify(const std::string& sender, const std::string& event) override {
        if (sender == "Button" && event == "click") {
            textBox->setText("Button was clicked");
        } else if (sender == "TextBox" && event == "setText") {
            std::cout << "TextBox content changed to: " << textBox->getText() << std::endl;
        }
    }
};

// Client Code
int main() {
    Dialog dialog;

    Button button;
    TextBox textBox;

    dialog.setButton(&button);
    dialog.setTextBox(&textBox);

    // Simulate user actions
    button.click();
    textBox.setText("New text");

    return 0;
}