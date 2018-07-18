#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int SumSquares(int total, int value)
{
    return total + value * value;
}

template<class T>
void PrintInterval(T first, T last)
{
    for (; first != last; ++first) {
        cout << *first << " ";
    }
    cout << endl;
}

template<class T>
class SumPowers
{
private:
    int power;
public:
    SumPowers(int p) : power(p) {};
    const T operator()(const T &total, const T &value)
    {
        T v = value;
        for (int i = 0; i < power - 1; i++) {
            v = v * value;
        }
        return total + v;
    }
};

int main()
{
    const int SIZE = 10;
    int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    vector<int> v(a1, a1 + SIZE);
    cout << "1. ";
    PrintInterval(v.begin(), v.end());

    /*
    template<class _InIt,
    class _Ty,
    class _Fn2> inline
    _Ty _Accumulate_unchecked(_InIt _First, _InIt _Last, _Ty _Val, _Fn2& _Func)
    {	// return sum of _Val and all in [_First, _Last), using _Func
        for (; _First != _Last; ++_First)
            Val = _Func(_Val, *_First);    
        return (_Val);
    }

    template<class _InIt,
	class _Ty,
	class _Fn2> inline
	_Ty accumulate(_InIt _First, _InIt _Last, _Ty _Val, _Fn2 _Func)
	{	// return sum of _Val and all in [_First, _Last), using _Func
	    _DEBUG_RANGE_PTR(_First, _Last, _Func);
	    return (_Accumulate_unchecked(_Unchecked(_First), _Unchecked(_Last), _Val, _Func));
	}
    */

    int result = accumulate(v.begin(), v.end(), 0, SumSquares);
    cout << "2. 平方和：" << result << endl;

    result = accumulate(v.begin(), v.end(), 0, SumPowers<int>(3));
    cout << "2. 立方和：" << result << endl;

    result = accumulate(v.begin(), v.end(), 0, SumPowers<int>(4));
    cout << "2. 四次方和：" << result << endl;

    
    return 0;
}