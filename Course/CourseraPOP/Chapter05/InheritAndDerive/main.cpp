#include "student.h"
#include "undergraduate.h"

int main()
{
    UndergraduateStudent s;
    s.SetInfo("Harry Potter", "11882983", 19, 'M', "Computer Science");
    cout << s.GetName() << endl;
    s.QualifiedForBaoyan();
    s.PrintInfo();

    return 0;
}