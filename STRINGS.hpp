#ifndef STRING_H
#define STRING_H

class STRING {
private:
    char* charArray;

    int CalcLength(const char* theString) const;

public:
    STRING(const char* theString);
    STRING();
    ~STRING();
    STRING substr(int pos, int len) const;
    void insert(int pos, const char* toInsert);
    void replace(int pos, int len, const char* replacement);
    void erase(int pos, int len);
    int length() const;
    void print() const;
};

#endif
