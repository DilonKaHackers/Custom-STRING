#include "STRING.hpp"
#include <iostream>
using namespace std;

int main() {
    // Test constructor and print
    STRING str1("Hello, World!");
    cout << "Original String: ";
    str1.print();

    // Test length()
    cout << "Length of str1: " << str1.length() << endl;

    // Test substr()
    STRING sub = str1.substr(7, 5);
    cout << "Substring of str1 from position 7 with length 5: ";
    sub.print();

    // Test insert()
    str1.insert(5, " beautiful");
    cout << "After inserting ' beautiful' at position 5: ";
    str1.print();

    // Test replace()
    str1.replace(7, 9, "awesome");
    cout << "After replacing 'beautiful' with 'awesome': ";
    str1.print();

    // Test erase()
    str1.erase(7, 7);
    cout << "After erasing 7 characters from position 7: ";
    str1.print();

    // Test reverse()
    str1.reverse();
    cout << "After reversing the string: ";
    str1.print();

    // Test toUpperCase()
    str1.toUpperCase();
    cout << "After converting to uppercase: ";
    str1.print();

    // Test toLowerCase()
    str1.toLowerCase();
    cout << "After converting to lowercase: ";
    str1.print();

    // Test trim()
    STRING str2("   Trim me!   ");
    str2.trim();
    cout << "After trimming str2: ";
    str2.print();

    // Test split()
    int count;
    STRING* substrings = str1.split(' ', count);
    cout << "Split str1 by space (" << count << " parts):" << endl;
    for (int i = 0; i < count; i++) {
        substrings[i].print();
    }
    delete[] substrings;

    // Test replaceAll()
    str1.replaceAll("me", "you");
    cout << "After replacing 'me' with 'you': ";
    str1.print();

    // Test startsWith()
    cout << "Does str1 start with 'hello'? " << (str1.startsWith("hello") ? "Yes" : "No") << endl;

    // Test endsWith()
    cout << "Does str1 end with 'you'? " << (str1.endsWith("you") ? "Yes" : "No") << endl;

    // Test count(char)
    cout << "Count of 'o' in str1: " << str1.count('o') << endl;

    // Test count(const char*)
    cout << "Count of 'lo' in str1: " << str1.count("lo") << endl;

    return 0;
}
