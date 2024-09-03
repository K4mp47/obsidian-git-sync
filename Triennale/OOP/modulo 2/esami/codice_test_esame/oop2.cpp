#include <iostream>

using namespace std;

template <class A, class B>
class mypair
{
private:
    A first;
    B second;

public:
    mypair() : first(), second() {}

    mypair(A _first, B _second) : first(_first), second(_second) {}

    // copy constructor
    mypair(const pair<A, B> &p) : first(p.first), second(p.second) {}

    // assignment operator
    mypair<A, B> &operator=(const mypair<A, B> &p)
    {
        first = p.first;
        second = p.second;
        return *this;
    }

    // operator++
    mypair<A, B> operator++(int)
    {
        auto tmp = *this;
        first++;
        second++;

        return tmp;
    }

    A fst() const { return first; }
    B snd() const { return second; }

    mypair<A, B> operator+(const mypair<A, B>& p) const
	{
		return mypair<A, B>(first + p.first, second + p.second);
	}
};

int main()
{
    mypair<int, int> p1 = mypair<int, int>(1, 2);
    mypair<int, int> p2 = mypair<int, int>(3, 4);

    p1 = p2;
    p1++;
    cout << p1.fst() << " " << p1.snd() << endl;
    return 0;
}