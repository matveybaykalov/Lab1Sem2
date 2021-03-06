//
// Created by bayka on 09.02.2021.
//

#include "String.h"
#include <iostream>

String::String() {
    root = nullptr;
}

String::String(const char* str){
    int size = 0;
    while (str[size] != '\0'){
        size++;
    }
    root = new char[size+1];
    int iter = 0;
    while (str[iter] != '\0'){
        root[iter] = str[iter];
        iter++;
    }
    root[iter] = '\0';
}

int String::length () const {
    int size = 0;
    if (root != nullptr) {
        while (root[size] != '\0') {
            size++;
        }
    }
    return size;
}

String::String(const String &str) {
    int size = str.length();
    root = new char[size+1];
    int iter = 0;
    while (str.root[iter] != '\0'){
        root[iter] = str.root[iter];
        iter++;
    }
    root[iter] = '\0';
}
String::~String() {
    delete [] root;
}

String& String::operator=(const String& str){
    if (this != &str) {
        int size = str.length();
        delete [] this->root;
        this->root = new char[size + 1];
        int iter = 0;
        while (str.root[iter] != '\0') {
            this->root[iter] = str.root[iter];
            iter++;
        }
        this->root[iter] = '\0';
    }
    return *this;
}

bool String::operator== (const String& rhs) const{
    int size = length();
    if(size == rhs.length()){
        for (int i = 0; i < size; ++i){
            if (root[i] != rhs.root[i]){
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

int String::substr(const String &str) const {
    for (int i = 0; i <= length()-str.length(); ++i){
        bool flag = true;
        //std::cout << str.length() << std::endl;
        for (int j = 0; j < str.length(); ++j) {
            if (root[i + j] != str.root[j]) {
                flag = false;
            }
        }
        if (flag){
            return i;
        }
    }
    return -1;
}

char String::operator[](int n) const{
    return root[n];
}

void String::replace(char chf, char chr) const{
    for (int i = 0; i < length(); ++i){
        if (root[i] == chf){
            root[i] = chr;
        }
    }
}

String operator+(const String& lhs, const String& rhs){
    String NewStr;
    int lhsS = lhs.length(), rhsS = rhs.length();
    int size = lhsS + rhsS;
    NewStr.root = new char [size+1];
    for (int i = 0; i < lhsS; ++i){
        NewStr.root[i] = lhs.root[i];
    }
    for (int i = 0; i < rhsS; ++i){
        NewStr.root[lhsS+i] = rhs.root[i];
    }
    NewStr.root[size] = '\0';
    return NewStr;
}

std::ostream& operator<< (std::ostream& stream,const String& str){
    for (int i = 0; i < str.length(); ++i){
        stream << str[i];
    }
    return stream;
}

std::istream& operator>> (std::istream& stream, String& str){
    char* temp = new char[256];
    stream >> temp;
    String temp2(temp);
    str = temp2;
    delete [] temp;
    return stream;
}