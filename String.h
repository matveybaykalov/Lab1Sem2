//
// Created by bayka on 09.02.2021.
//

#ifndef LAB1SEM2_STRING_H
#define LAB1SEM2_STRING_H

#include <iostream>


class String {
private:
    char* root;
public:
    String ();
    String (const String&);
    explicit String (const char*);
    ~String ();
    String& operator=(const String&);
    bool operator==(const String&) const;
    int length() const;
    int substr(const String&) const;
    char operator[](int) const;
    void replace (char, char);
    String& operator+(const String&);
};

std::ostream& operator<< (std::ostream&,const String&);
std::istream& operator>> (std::istream& stream, String& str);

#endif //LAB1SEM2_STRING_H
