#include "STRING.h"
#include <iostream>
using namespace std;

int main() {
    STRING str("Hello, World!");
    cout << "String length: " << str.length() << endl;
    str.print();

    STRING subStr = str.substr(7, 5);
    cout << "Substring: ";
    subStr.print();

    str.insert(7, "Beautiful ");
    cout << "After Insert: ";
    str.print();

    str.replace(7, 9, "Awesome");
    cout << "After Replace: ";
    str.print();

    str.erase(7, 7);
    cout << "After Erase: ";
    str.print();

    return 0;
}
