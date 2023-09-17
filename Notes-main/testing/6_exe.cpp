#include <iostream>

template<typename T> class stack{
public:
    stack();
    stack(const stack<T>& l);
    ~stack();
    T& top();
    stack<T>& operator--();
    stack<T>& operator+(const T& l);
    stack<T>& operator+=(const T& l);
    stack<T>& operator=(const stack<T>& l);

private:
    struct Cell {
        T number;
        Cell* next;  
    };
    
    Cell* head;
    Cell* tail;
};

template<typename T>
stack<T>::stack(){
    head = nullptr;
    tail = nullptr;
}

template<typename T>
stack<T>::stack(const stack<T>& l){
    if(!l.head)
        head = tail = nullptr;
    else {
        head = nullptr;
        Cell* temp = l.head;
        Cell* tempCopy = head;
        Cell* newnode = new Cell();
        newnode->next = nullptr;
        newnode->number = temp->number;
        tempCopy = newnode;
        head = tail = tempCopy;
        temp = temp->next;
        while(temp!=nullptr){
            Cell* newnode = new Cell();
            newnode->next = nullptr;
            newnode->number = temp->number;
            tempCopy->next = newnode;
            tail = newnode;
            tempCopy = tempCopy->next;
            temp = temp->next;
        }
    }
}

template<typename T>
stack<T>::~stack(){
    Cell* temp = head;
    while(temp != nullptr){
        Cell* d = temp;
        temp = temp->next;
        delete d;
    }
    tail = head = nullptr;
}

template<typename T>
stack<T>& stack<T>::operator--(){
    if(!head)
        return *this;
    Cell* temp = head;
    if(tail != head){
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        temp->next = nullptr;
        tail = temp;
    } else 
        delete temp, tail = head = nullptr;
    return *this;
};

template<typename T>    
stack<T>& stack<T>::operator+(const T& l){
    stack<T>& copy = *this;
    Cell* newnode = new Cell();
    newnode->next = nullptr;
    newnode->number = l;
    copy.tail->next = newnode;
    copy.tail = newnode;
    return copy;
};

template<typename T>    
stack<T>& stack<T>::operator+=(const T& l){
        Cell* newnode = new Cell();
        if(!head){
            newnode->number = l;
            newnode->next = nullptr;
            head = tail = newnode;
        } else {
            newnode->number = l;
            newnode->next = nullptr;
            tail->next = newnode;
            tail = tail->next;
        }
        return *this;
};
    
template<typename T>
stack<T>& stack<T>::operator=(const stack<T>&){
        return *this;
};

template<typename T>
T& stack<T>::top(){
    return tail->number;
}


int main(){
    
    int N {};
    std::cin >> N;
    N *= 2;
    
    using T = int;
    
    stack<T> S1;
    
    T x,y;
    for(int i=0;i<N/2;++i){
        std::cin >> x >> y;
        (S1 += x) += y;
    }
    
    stack<T> S2 = stack<T>{S1} + N;
    
    S2 = S2;
        
    for(int i = 0; i<N-1;++i){
        std::cout << (--S1).top()++ << std::endl;
        S2 += S1.top();
    }

    for(int i = 0; i<2*N;++i){
        
        std::cout << S2.top() << std::endl;
        --S2;
        
    }
    
    for(int i = 0; i<100;++i) --S2;
    
}
