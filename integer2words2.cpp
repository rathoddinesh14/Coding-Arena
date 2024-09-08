#include <iostream>
#include <string>
#include <map>

using namespace std;

// Maps to store number-to-word conversions
map<int, string> ones = {
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
    {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
    {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"},
    {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"},
    {19, "nineteen"}
};

map<int, string> tens = {
    {2, "twenty"}, {3, "thirty"}, {4, "forty"}, {5, "fifty"},
    {6, "sixty"}, {7, "seventy"}, {8, "eighty"}, {9, "ninety"}
};

// Function to convert hundreds to words
string convertHundreds(int num) {
    string result;

    if (num >= 100) {
        result += ones[num / 100] + " hundred";
        num %= 100;
        if (num > 0) {
            result += " ";
        }
    }

    if (num >= 20) {
        result += tens[num / 10];
        num %= 10;
        if (num > 0) {
            result += "-" + ones[num];
        }
    } else if (num > 0) {
        result += ones[num];
    }

    return result;
}

// Main function to convert any number up to 999,999,999 to words
string numberToWords(int num) {
    if (num == 0) {
        return "zero";
    }

    string result;
    if (num >= 1000000) {
        result += convertHundreds(num / 1000000) + " million";
        num %= 1000000;
        if (num > 0) {
            result += ", ";
        }
    }

    if (num >= 1000) {
        result += convertHundreds(num / 1000) + " thousand";
        num %= 1000;
        if (num > 0) {
            result += ", ";
        }
    }

    if (num > 0) {
        result += convertHundreds(num);
    }

    return result;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 0 || number > 999999999) {
        cout << "Number out of range! Please enter a number between 0 and 999,999,999." << endl;
    } else {
        cout << numberToWords(number) << endl;
    }

    return 0;
}
