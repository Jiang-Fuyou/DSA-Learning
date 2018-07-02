#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
using namespace std;

/*
void qsort(void *base, int nelem, unsigned int width,
int(*compare)(const void *, const void *));
*/

struct ScoreList
{
    int score;
    string name;
};

int MyCompare(const void *elmt1, const void *elmt2)
{
    ScoreList *s1, *s2;
    s1 = (ScoreList *)elmt1;
    s2 = (ScoreList *)elmt2;
    return s1->score < s2->score;
}

int main()
{
    ScoreList a[4];

    a[0].name = "Liu Heihei";
    a[0].score = 65;
    a[1].name = "Li Haha";
    a[1].score = 75;
    a[2].name = "Wang Hehe";
    a[2].score = 85;
    a[3].name = "Zhao Moumou";
    a[3].score = 95;

    qsort(a, 4, sizeof(ScoreList), MyCompare);

    for (size_t i = 0; i < 4; i++) {
        cout << "Name: " << a[i].name << ".\t Score: " << a[i].score << endl;
    }

    return 0;
}    