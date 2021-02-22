#include <iostream>
#include "String.h"

int main() {
    String MyStr("Hello");
    String str = MyStr;
    std::cout << MyStr.length() << ' ' << str.length() << std::endl;
    if(str == MyStr) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    String el("aab"), NewStr("aacabbcaab");
    std::cout<<NewStr.substr(el)<<std::endl;
    MyStr.replace('l', 'w');
    std::cout << MyStr << std::endl;
    String str0;
    std::cout <<"Enter the string" << std::endl;
    std::cin >> str0;
    std::cout << str+str0 << std::endl;
    return 0;
}
