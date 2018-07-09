#include "employee.h"

int main()
{
    Employee e;
    e.salary = 5000; // RIGHT
    // e.name = "Tom"; // WRONG
    e.setName("Tom");
    
    return 0;
}