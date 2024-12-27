#include "STRINGS.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

int STRING::CalcLength(const char* theString) const {
    int count = 0;
    while (theString[count] != '\0') {
        count++;
    }
    return count;
}

STRING::STRING(const char* theString) {
    int len = CalcLength(theString);
    charArray = new char[len + 1];
    for (int i = 0; i < len; i++) {
        charArray[i] = theString[i];
    }
    charArray[len] = '\0';
}

STRING::STRING() : charArray(nullptr) {}

STRING::~STRING() {
    delete[] charArray;
}

STRING STRING::substr(int pos, int len) const {
    if (pos < 0 || pos >= CalcLength(charArray) || len < 0) {
        throw out_of_range("Invalid position or length");
    }
    int newLen = (pos + len > CalcLength(charArray)) ? CalcLength(charArray) - pos : len;
    char* subArray = new char[newLen + 1];
    for (int i = 0; i < newLen; i++) {
        subArray[i] = charArray[pos + i];
    }
    subArray[newLen] = '\0';
    return STRING(subArray);
}

void STRING::insert(int pos, const char* toInsert) {
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

void STRING::replace(int pos, int len, const char* replacement) {
    if (pos < 0 || pos >= CalcLength(charArray) || len < 0) {
        throw out_of_range("Invalid position or length");
    }
    erase(pos, len);
    insert(pos, replacement);
}

void STRING::erase(int pos, int len) {
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

int STRING::length() const {
    return CalcLength(charArray);
}

void STRING::reverse() {
    int len = length();
    for (int i = 0; i < len / 2; i++) {
        char temp = charArray[i];
        charArray[i] = charArray[len - 1 - i];
        charArray[len - 1 - i] = temp;
    }
}

void STRING::toUpperCase() {
    for (int i = 0; i < length(); i++) {
        if (charArray[i] >= 'a' && charArray[i] <= 'z') {
            charArray[i] -= 32;
        }
    }
}

void STRING::toLowerCase() {
    for (int i = 0; i < length(); i++) {
        if (charArray[i] >= 'A' && charArray[i] <= 'Z') {
            charArray[i] += 32;
        }
    }
}

void STRING::trim() {
    int start = 0, end = length() - 1;
    while (charArray[start] == ' ' && start < end) {
        start++;
    }
    while (charArray[end] == ' ' && end > start) {
        end--;
    }
    int newLength = end - start + 1;

    char* newArray = new char[newLength + 1];
    for (int i = 0; i < newLength; i++) {
        newArray[i] = charArray[start + i];
    }
    newArray[newLength] = '\0';

    delete[] charArray;
    charArray = newArray;
}

STRING* STRING::split(char delimiter, int& count) const {
    count = 1;
    for (int i = 0; i < length(); i++) {
        if (charArray[i] == delimiter) count++;
    }

    STRING* substrings = new STRING[count];
    int start = 0, idx = 0;

    for (int i = 0; i <= length(); i++) {
        if (charArray[i] == delimiter || charArray[i] == '\0') {
            substrings[idx++] = substr(start, i - start);
            start = i + 1;
        }
    }

    return substrings;
}

void STRING::replaceAll(const char* target, const char* replacement) {
    int targetLen = CalcLength(target);
    int replaceLen = CalcLength(replacement);

    for (int i = 0; i <= length() - targetLen; i++) {
        bool match = true;
        for (int j = 0; j < targetLen; j++) {
            if (charArray[i + j] != target[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            erase(i, targetLen);
            insert(i, replacement);
            i += replaceLen - 1;
        }
    }
}

bool STRING::startsWith(const char* prefix) const {
    int prefixLen = CalcLength(prefix);
    if (prefixLen > length()) return false;
    for (int i = 0; i < prefixLen; i++) {
        if (charArray[i] != prefix[i]) return false;
    }
    return true;
}

bool STRING::endsWith(const char* suffix) const {
    int suffixLen = CalcLength(suffix);
    int strLen = length();
    if (suffixLen > strLen) return false;
    for (int i = 0; i < suffixLen; i++) {
        if (charArray[strLen - suffixLen + i] != suffix[i]) return false;
    }
    return true;
}

int STRING::count(char character) const {
    int count = 0;
    for (int i = 0; i < length(); i++) {
        if (charArray[i] == character) count++;
    }
    return count;
}

int STRING::count(const char* substring) const {
    int substringLen = CalcLength(substring);
    int occurrences = 0;

    for (int i = 0; i <= length() - substringLen; i++) {
        bool match = true;
        for (int j = 0; j < substringLen; j++) {
            if (charArray[i + j] != substring[j]) {
                match = false;
                break;
            }
        }
        if (match) occurrences++;
    }

    return occurrences;
}


void STRING::print() const {
    if (charArray) {
        cout << charArray << endl;
    } else {
        cout << "(empty string)" << endl;
    }
}
