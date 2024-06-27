#include "IPrinter.h"
#include "OldPrinter.h"
#include "PrinterAdapter.h"

int main() {
    OldPrinter oldPrinter;
    PrinterAdapter adapter(&oldPrinter);

    // Client uses the new interface
    adapter.print("Hello, World!");

    return 0;
}
