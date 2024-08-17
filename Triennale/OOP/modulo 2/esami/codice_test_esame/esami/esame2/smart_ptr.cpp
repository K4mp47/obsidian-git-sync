#include <iostream>

using namespace std;

template <typename T>
class smart_ptr
{
private:
    T* ptr;
    int* count;

public:
    // default constructor
    smart_ptr() : ptr(nullptr), count(new int(0)) {}

    // copy constructor
    smart_ptr(T* ptr) : ptr(ptr), count(new int(1)) {}

    // move constructor
    smart_ptr(smart_ptr&& other) : ptr(other.ptr), count(other.count)
    {
        other.ptr = nullptr;
        other.count = nullptr;
    }

    // copy assignment
    smart_ptr& operator=(const smart_ptr& other)
    {
        if(this != &other)
        {
            ~smart_ptr();
            this->ptr = other.ptr;
            this->count = other.count;
            (*this->count)++;
        }
        return *this;
    }

    // move assignment
    smart_ptr& operator=(smart_ptr& other)
    {
        if(this != &other)
        {
            ~smart_ptr();
            this->ptr = other.ptr;
            this->count = other.count;
            (*this->count)++;
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    T* get() const
    {
        return ptr;
    }

    T& operator()(){
        return *this;
    }

    T& operator*() const
    {
        return *ptr;
    }

    T* operator->() const
    {
        return ptr;
    }

    // post-increment
    smart_ptr& operator++()
    {
        (ptr)++;
        return *this;
    }

    // post-decrement
    smart_ptr& operator--()
    {
        (ptr)--;
        return *this;
    }

    // pre-increment
    smart_ptr& operator++(int)
    {
        smart_ptr tmp = *this;
        (ptr)++;
        return tmp;
    }

    // pre-decrement
    smart_ptr& operator--(int)
    {
        smart_ptr tmp = *this;
        (ptr)--;
        return tmp;
    }

    smart_ptr& operator-(int n) const 
    {
        ptr -= n;
        return *this;
    }

    smart_ptr& operator+(int n) const 
    {
        ptr += n;
        return *this;
    }

    bool operator==(const smart_ptr& other) const
    {
        return ptr == other.ptr;
    }

    smart_ptr& operator+=(int n)
    {
        ptr += n;
        return *this;
    }

    smart_ptr& operator-=(int n)
    {
        ptr -= n;
        return *this;
    }
};

int main()
{
    int b = 10;
    int* a = &b; 
    smart_ptr<int> p(a);
    cout << a << endl;
    cout << p.get() << endl;
    cout << (++p).get() << endl;
    cout << (--p).get() << endl;
    cout << *(p).get() << endl;
}