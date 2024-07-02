#include "ProxyImage.h"

int main() {
    Image* image = new ProxyImage("test_image.jpg");

    // Image will be loaded from disk only once, when it is needed
    image->display(); // Loading test_image.jpg from disk... Displaying test_image.jpg
    image->display(); // Displaying test_image.jpg

    delete image;
    return 0;
}
