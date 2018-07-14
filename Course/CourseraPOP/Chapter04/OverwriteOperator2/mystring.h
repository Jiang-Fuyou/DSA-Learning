#pragma once

#include <string.h>
#include <iostream>
using namespace std;


class String
{
public:
    String();
    ~String();
    const char *c_str();
    char *operator=(const char *s);
    String &operator=(const String &s); // Éî¿½±´
private:
    char *str;
};

String::String()
{
    str = nullptr;
}

String::~String()
{
    if (str) {
        delete[]str;
    }
}

const char *String::c_str()
{
    return str;
}

char *String::operator=(const char *s)
{
    if (str) {
        delete []str;
    }

    if (s) {
        str = new char[strlen(s) + 1]; // \0
        strcpy(str, s);
    } else {
        str = nullptr;
    }

    return str;
}

String &String::operator=(const String &s)
{
    // str == this->str;
    if (str == s.str) {
        return *this;
    }

    if (str) {
        delete[]str;
    }

    if (s.str) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    } else {
        str = nullptr;
    }

    return *this;
}