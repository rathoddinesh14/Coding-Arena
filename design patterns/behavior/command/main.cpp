#include <iostream>
#include <string>
#include <stack>
#include <memory>

// Command Interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver
class TextEditor {
private:
    std::string text;

public:
    void appendText(const std::string& newText) {
        text += newText;
    }

    void deleteText(size_t length) {
        if (length <= text.size()) {
            text.erase(text.size() - length, length);
        }
    }

    void printText() const {
        std::cout << "Current text: " << text << std::endl;
    }
};

// Concrete Command: AppendTextCommand
class AppendTextCommand : public Command {
private:
    TextEditor& editor;
    std::string textToAppend;

public:
    AppendTextCommand(TextEditor& editor, const std::string& text)
        : editor(editor), textToAppend(text) {}

    void execute() override {
        editor.appendText(textToAppend);
    }

    void undo() override {
        editor.deleteText(textToAppend.size());
    }
};

// Invoker
class CommandManager {
private:
    std::stack<std::unique_ptr<Command>> commandHistory;

public:
    void executeCommand(std::unique_ptr<Command> command) {
        command->execute();
        commandHistory.push(std::move(command));
    }

    void undoCommand() {
        if (!commandHistory.empty()) {
            commandHistory.top()->undo();
            commandHistory.pop();
        }
    }
};

// Client Code
int main() {
    TextEditor editor;
    CommandManager manager;

    editor.printText();

    manager.executeCommand(std::make_unique<AppendTextCommand>(editor, "Hello, "));
    editor.printText();

    manager.executeCommand(std::make_unique<AppendTextCommand>(editor, "World!"));
    editor.printText();

    manager.undoCommand();
    editor.printText();

    manager.undoCommand();
    editor.printText();

    return 0;
}
