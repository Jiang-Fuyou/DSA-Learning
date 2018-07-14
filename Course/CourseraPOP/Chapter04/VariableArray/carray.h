#pragma once

#include <string.h>

class CArray
{
public:
    CArray(int s = 0);
    CArray(const CArray &a);
    ~CArray();
    void push_back(const int v);
    int length();
    CArray &operator=(const CArray &a);
    int &operator[](int i); // 非引用的函数返回值不可以作为左值使用
                            // 使用引用也可以修改相应元素
private:
    int size;
    int *ptr;
};

CArray::CArray(int s) : size(s)
{
    if (s == 0) {
        ptr = nullptr;
    } else {
        ptr = new int[s];
    }
}

CArray::CArray(const CArray &a)
{
    // 如果a是空的
    if (!a.ptr) {
        ptr = nullptr;
        size = 0;
        return;
    }

    // 如果a非空，则开辟内存空间，并将a的对应成员变量复制给新的CArray对象
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, a.size * sizeof(int));
    size = a.size;
}

CArray::~CArray()
{
    if (ptr) {
        delete[]ptr;
    }
}

CArray &CArray::operator=(const CArray &a)
{
    if (ptr = a.ptr) {
        return *this;
    }

    if (!a.ptr) {
        if (ptr) {
            delete []ptr;
        }
        ptr = nullptr;
        size = 0;

        return *this;
    }

    if (size < a.size) { // 如果原空间够大，则不需要重新分配空间
        if (ptr) {
            delete[]ptr;
        }
        ptr = new int[a.size];
    }

    size = a.size;
    memcpy(ptr, a.ptr, a.size * sizeof(int));

    return *this;
}

int CArray::length()
{
    return size;
}

void CArray::push_back(const int v)
{
    if (ptr) {
        int *tmpPtr = new int[size + 1];
        memcpy(tmpPtr, ptr, size * sizeof(int));
        delete[]ptr;
        ptr = tmpPtr;
    } else {
        ptr = new int[1];
    }
    ptr[size++] = v;
}

int &CArray::operator[](const int i)
{
    return ptr[i];
}