// PrinterAdapter.h
#pragma once
#include "IPrinter.h"
#include "OldPrinter.h"

class PrinterAdapter : public IPrinter {
public:
    PrinterAdapter(OldPrinter* oldPrinter) : oldPrinter(oldPrinter) {}

    void print(const std::string& text) override {
        oldPrinter->printOld(text);
    }

private:
    OldPrinter* oldPrinter;
};
