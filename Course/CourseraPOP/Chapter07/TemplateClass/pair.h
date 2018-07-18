#pragma once

template <class T1, class T2>
class Pair
{
public:
    T1 key;
    T2 value;
    Pair(T1 k, T2 v) : key(k), value(v) {};
    ~Pair() {};
    bool operator<(const Pair<T1, T2> &p) const;
};

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const
{
    return key < p.key;
}

