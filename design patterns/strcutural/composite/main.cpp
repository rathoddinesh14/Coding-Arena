#include "Button.h"
#include "TextField.h"
#include "Panel.h"

int main() {
    // Create individual components
    Button* button1 = new Button("Submit");
    Button* button2 = new Button("Cancel");
    TextField* textField = new TextField("Enter your name");

    // Create a panel and add components to it
    Panel* panel = new Panel();
    panel->add(button1);
    panel->add(button2);
    panel->add(textField);

    // Create another panel
    Panel* mainPanel = new Panel();
    mainPanel->add(panel); // Add the first panel to the main panel

    // Render the main panel
    mainPanel->render();

    // Clean up
    delete button1;
    delete button2;
    delete textField;
    delete panel;
    delete mainPanel;

    return 0;
}
