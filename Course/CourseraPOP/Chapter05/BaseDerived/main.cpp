#include "base.h"
#include "derived.h"
#include "father.h"
#include "son.h"

int main()
{
    Derived obj;
    obj.i = 1;
    obj.Base::i = 1;

    Father f;
    Son s;

    f.nPublic = 1;
    s.nPublic = 1;

    // The followings are error!
    // f.nProtected = 1;
    // s.nProtected = 1;
    // f.nPrivate = 1;
    // s.nPrivate = 1;

    return 0;
}