#include <iostream>
#include <mutex>

class Singleton {
    public:
        // Delete copy constructor and assignment operator to ensure singleton
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        // Method to get the single instance of the class
        static Singleton& getInstance() {
            static Singleton instance; // Guaranteed to be destroyed, instantiated on first use
            return instance;
        }

        void showMessage() {
            std::cout << "Hello from Singleton!" << std::endl;
        }

    private:
        // Private constructor to prevent instantiation
        Singleton() {
            std::cout << "Singleton instance created!" << std::endl;
        }
};

int main() {
    // Get the only instance of Singleton
    Singleton& singleton = Singleton::getInstance();
    singleton.showMessage();

    // Uncommenting the following lines will cause a compilation error
    // Singleton anotherSingleton = Singleton::getInstance();
    // Singleton copySingleton(singleton);
    // copySingleton = singleton;

    return 0;
}
