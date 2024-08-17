#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <functional>

using namespace std;

template <typename T, typename R>
class Function
{
public:
    virtual R apply(T t) {};
};

template <typename C, typename D>
class Pair
{
private:
    C c;
    D d;

public:
    Pair(C c, D d)
    {
        this->c = c;
        this->d = d;
    }

    C getFirst()
    {
        return c;
    }

    D getSecond()
    {
        return d;
    }
};

template <typename A>
class PairIterator
{
public:
    using InputIterator = typename vector<A>::iterator;

    PairIterator(InputIterator it, InputIterator end)
        : it(it), end(end), last(), has_last(false) {}

    bool hasNext()
    {
        if (!has_last && it != end)
        {
            last = *it++;
            has_last = true;
        }
        return it != end;
    }

    Pair<A, A> next()
    {
        if (!has_last)
        {
            throw std::out_of_range("No more elements");
        }
        Pair<A, A> result(last, *it++);
        has_last = false;
        return result;
    }

private:
    InputIterator it;
    InputIterator end;
    A last;
    bool has_last;
};

template <typename A>
PairIterator<A> pairIterator(typename vector<A>::iterator it, typename std::vector<A>::iterator end)
{
    return PairIterator<A>(it, end);
}

template <typename A, typename T, typename R>
class MapIterator
{
public:
    MapIterator(PairIterator<A> _it, function<R(T)> _f)
        : it(_it), f(_f) {}

    bool hasNext()
    {
        return it.hasNext();
    }

    R next()
    {
        // execute the lambda function on the next element
        return f(it.next());
    }

private:
    PairIterator<A> it;
    function<R(T)> f;
};

template <typename A, typename T, typename R>
MapIterator<A, T, R> mapIterator(PairIterator<A> it, function<R(T)> f)
{
    return MapIterator<A, T, R>(it, f);
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = pairIterator<int>(vec.begin(), vec.end());

    while (it.hasNext())
    {
        auto p = it.next();
        std::cout << "(" << p.getFirst() << ", " << p.getSecond() << ") ";
    }
    std::cout << std::endl;

    it = pairIterator<int>(vec.begin(), vec.end());

    // call mapIterator
    auto it2 = mapIterator<int, Pair<int, int>, double>(it, [](Pair<int, int> x) -> double
                                                        { return x.getFirst() * 2; });

    while (it2.hasNext())
    {
        std::cout << it2.next() << " ";
    }
    return 0;
}