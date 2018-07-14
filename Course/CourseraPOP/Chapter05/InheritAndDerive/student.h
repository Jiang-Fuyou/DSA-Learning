#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student();
    ~Student();
    void PrintInfo();
    void SetInfo(const string &name_, const string &id_, const int age_, 
                 const char gender_);
    string GetName() { return name; }
private:
    string name;
    string id;
    char gender;
    int age;
};

Student::Student()
{}

Student::~Student()
{}

void Student::SetInfo(const string &name_, const string &id_, const int age_,
                      const char gender_)
{
    name = name_;
    id = id_;
    age = age_;
    gender = gender_;
}

void Student::PrintInfo()
{
    cout << name << endl;
    cout << id << endl;
    cout << age << endl;
    cout << gender << endl;
}