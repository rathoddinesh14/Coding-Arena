#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Helper function to convert numbers 1-19 to words
string convertOnes(int num) {
    vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                           "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                           "seventeen", "eighteen", "nineteen"};
    return ones[num];
}

// Helper function to convert tens (20, 30, ... 90) to words
string convertTens(int num) {
    vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    return tens[num];
}

// Function to convert hundreds to words
string convertHundreds(int num) {
    string result;

    if (num >= 100) {
        result += convertOnes(num / 100) + " hundred";
        num %= 100;
        if (num > 0) {
            result += " ";
        }
    }

    if (num >= 20) {
        result += convertTens(num / 10);
        num %= 10;
        if (num > 0) {
            result += "-" + convertOnes(num);
        }
    } else if (num > 0) {
        result += convertOnes(num);
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

