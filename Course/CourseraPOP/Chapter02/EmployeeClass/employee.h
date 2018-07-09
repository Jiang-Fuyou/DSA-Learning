#pragma once

#include <string.h>

class Employee
{
public:
    int salary;
    Employee();
    ~Employee();
    void setName(char *name);
    void getName(char *name);
    void averageSalary(Employee e1, Employee e2);

private:
    char szName[30];
};

Employee::Employee()
{}

Employee::~Employee()
{}

void Employee::setName(char *name)
{
    strcpy(szName, name);
}

void Employee::getName(char *name)
{
    strcpy(name, szName);
}

void Employee::averageSalary(Employee e1, Employee e2)
{
    salary = 0.5 * (e1.salary + e2.salary);
}