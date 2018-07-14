#pragma once

#include "student.h"

class UndergraduateStudent : public Student
{
public:
    UndergraduateStudent();
    ~UndergraduateStudent();
    void QualifiedForBaoyan();
    void PrintInfo();
    void SetInfo(const string &name_, const string &id_, const int age_,
                 const char gender_, const string &department);
private:
    string department;
};

UndergraduateStudent::UndergraduateStudent()
{}

UndergraduateStudent::~UndergraduateStudent()
{}

void UndergraduateStudent::QualifiedForBaoyan()
{
    cout << "Qualified for baoyan." << endl;
}

void UndergraduateStudent::PrintInfo()
{
    Student::PrintInfo();
    cout << department << endl;
}

void UndergraduateStudent::SetInfo(const string &name_, const string &id_,
                                   const int age_, const char gender_,
                                   const string &department_)
{
    Student::SetInfo(name_, id_, age_, gender_);
    department = department_;
}