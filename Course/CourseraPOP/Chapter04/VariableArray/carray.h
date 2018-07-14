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
    int &operator[](int i); // �����õĺ�������ֵ��������Ϊ��ֵʹ��
                            // ʹ������Ҳ�����޸���ӦԪ��
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
    // ���a�ǿյ�
    if (!a.ptr) {
        ptr = nullptr;
        size = 0;
        return;
    }

    // ���a�ǿգ��򿪱��ڴ�ռ䣬����a�Ķ�Ӧ��Ա�������Ƹ��µ�CArray����
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

    if (size < a.size) { // ���ԭ�ռ乻������Ҫ���·���ռ�
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