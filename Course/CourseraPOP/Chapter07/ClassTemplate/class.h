#pragma once

/******************************************************************************/

template<class T1, class T2>
class A
{
public:
    T1 v1;
    T2 v2;
};

/******************************************************************************/

template<class T1, class T2>
class B : public A<T1, T2>
{
public:
    T1 v3;
    T2 v4;
};


/******************************************************************************/

template<class T>
class C : public B<T, T>
{
public:
    T v5;
};

/******************************************************************************/
 