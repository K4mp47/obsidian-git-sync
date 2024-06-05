#include <iostream>

template <class A, class B>
class pair
{
private:
    A first;
    B second;

public:
    pair(A _first, B _second) : first(_first), second(_second) {}
    pair(const pair<A, B> &c) : first(c.getFirst()), second(c.getSecond()) {}
    
    // template <class C, class D>
    // pair(const pair<C, D> &d) : {}
    
    A getFirst() const { return first; }
    B getSecond() const { return second; }
    
    pair<A, B> getPair() { return *this; }
    
    const pair<A, B> operator()(A a, B b) {
        first = a;
        second = b;
        return *this;
    }

    pair& operator=(const pair& other) {
        if(this == &other){
            return *this;
        }

        this->first = other.getFirst();
        this->second = other.getSecond();

        return *this;
    }
};

int main()
{
    pair<int, int> p(1, 2);
    pair<int, int> e(4, 5);
    p = e;
    p = p(7, 8);
    std::cout << p.getFirst() << " " << p.getSecond() << std::endl;
    return 0;
}
