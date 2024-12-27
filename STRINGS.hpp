#ifndef STRING_H
#define STRING_H

class STRING {
private:
    char* charArray;
    int CalcLength(const char* theString) const;

public:
    //constructor,destructor
    STRING(const char* theString);
    STRING();
    ~STRING();
    //functions
    STRING substr(int pos, int len) const;
    void insert(int pos, const char* toInsert);
    void replace(int pos, int len, const char* replacement);
    void erase(int pos, int len);
    int length() const;
    void reverse();
    void toUpperCase();
    void toLowerCase();
    void trim();
    STRING* split(char delimiter, int& count) const;
    void replaceAll(const char* target, const char* replacement);
    bool startsWith(const char* prefix) const;
    bool endsWith(const char* suffix) const;
    int count(char character) const;
    int count(const char* substring) const;
    void print() const;
};

#endif
