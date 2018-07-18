#include "example.h"

CShape *pShapes[100];
int MyCompare(const void *s1, const void *s2);

int main()
{
    int i, n;

    CRectangle *pr;
    CCircle *pc;
    CTriangle *pt;

    cin >> n;

    for (size_t i = 0; i < n; i++) {
        char c;
        cin >> c;
        switch (c) {
        case 'R':
            pr = new CRectangle();
            cin >> pr->w >> pr->h;
            pShapes[i] = pr;
            break;
        case 'C':
            pc = new CCircle();
            cin >> pc->r;
            pShapes[i] = pc;
            break;
        case 'T':
            pt = new CTriangle();
            cin >> pt->a >> pt->b >> pt->c;
            pShapes[i] = pt;
            break;
        default:
            break;
        }
    }

    // pShape 实际上是一个指针数组，数组中每一个指针都指向一个C对象
    qsort(pShapes, n, sizeof(CShape *), MyCompare);
    for (size_t i = 0; i < n; i++) {
        pShapes[i]->PrintInfo();
    }

    return 0;
}

int MyCompare(const void *s1, const void *s2)
{
    double a1, a2;
    CShape **p1; // 指向指针的指针
    CShape **p2;

    p1 = (CShape **)s1;
    p2 = (CShape **)s2;

    a1 = (*p1)->Area();
    a2 = (*p2)->Area();

    if (a1 < a2) {
        return -1;
    } else if (a1 > a2) {
        return 1;
    } else {
        return 0;
    }
}