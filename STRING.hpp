#ifdef STRING_HPP
#define STRING_HPP

#include <iostream>
using namespace std;

class String {
private:
    char* charArray;

    int CalcLength(const char* theString) const {
        int count = 0;
        while (theString[count] != '\0') {
            count++;
        }
        return count;
    }

public:
    // Constructor and Destructor
    String_(const char* theString) {
        int len = CalcLength(theString);
        charArray = new char[len + 1];
        for (int i = 0; i < len; i++) {
            charArray[i] = theString[i];
        }
        charArray[len] = '\0';
    }

    String_() : charArray(nullptr) {}

    ~String_() {
        delete[] charArray;
    }

    // Functions
    String_ substr(int pos, int len) const {
        if (pos < 0 || pos >= CalcLength(charArray) || len < 0) {
            throw out_of_range("Invalid position or length");
        }

        int newLen = (pos + len > CalcLength(charArray)) ? CalcLength(charArray) - pos : len;
        char* subArray = new char[newLen + 1];

        for (int i = 0; i < newLen; i++) {
            subArray[i] = charArray[pos + i];
        }
        subArray[newLen] = '\0';

        return String_(subArray);
    }

    void insert(int pos, const char* toInsert) {
        if (pos < 0 || pos > CalcLength(charArray)) {
            throw out_of_range("Invalid position");
        }

        int originalLen = CalcLength(charArray);
        int insertLen = CalcLength(toInsert);
        char* newArray = new char[originalLen + insertLen + 1];

        for (int i = 0; i < pos; i++) {
            newArray[i] = charArray[i];
        }

        for (int i = 0; i < insertLen; i++) {
            newArray[pos + i] = toInsert[i];
        }

        for (int i = pos; i < originalLen; i++) {
            newArray[insertLen + i] = charArray[i];
        }
        newArray[originalLen + insertLen] = '\0';

        delete[] charArray;
        charArray = newArray;
    }


    void replace(int pos, int len, const char* replacement) {
        if (pos < 0 || pos >= CalcLength(charArray) || len < 0) {
            throw out_of_range("Invalid position or length");
        }

        erase(pos, len);
        insert(pos, replacement);
    }


    void erase(int pos, int len) {
        if (pos < 0 || pos >= CalcLength(charArray) || len < 0) {
            throw out_of_range("Invalid position or length");
        }

        int originalLen = CalcLength(charArray);
        if (pos + len > originalLen) {
            len = originalLen - pos;
        }

        char* newArray = new char[originalLen - len + 1];

        for (int i = 0; i < pos; i++) {
            newArray[i] = charArray[i];
        }

        for (int i = pos + len; i < originalLen; i++) {
            newArray[i - len] = charArray[i];
        }
        newArray[originalLen - len] = '\0';

        delete[] charArray;
        charArray = newArray;
    }

    void print() const {
        if (charArray) {
            cout << charArray << endl;
        } else {
            cout << "(empty string)" << endl;
        }
    }
};

#endif STRING_HPP
