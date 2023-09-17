Definition: 
```cpp
list<Val>
```

si vedranno anche gli iteratori e i constructor/copy constructor.
```cpp
#pragma once // implementazione forzata di un unica hpp

#include <iostream>

template<typename Val>
class list{
	struct node{
		Val val;
		node* next;
	};
	
public:

	//default constructor
	list();

	//list of one element
	list(Val v);

	//destructor
	~list();

	// mettere il * dopo const permette di modificare il puntatore, ma non
	// ció a cui punta.
	node const* front() const; // restituisce un puntatore alla prima cella
	node const* back() const; // lo restituisce ma alla ultima cella

	// add at the start
	void push_front(Val v);

	// add at the end
	void push_back(Val v);

	//remove first element from the list
	void pop_front();
	//remove last element from the list
	void pop_back();

	bool empty() const; // true if the list is empty

	bool operator==(list<Val> const& rhs) const; // controlla se uguale ad rhs
	bool operator!=(list<Val> const& rhs) const; // controlla se diverso ad rhs

	//l1 += l2
	// reference in ritorno per permettere la concatenazione
	list<Val>& operator+=(list<Val> const& rhs);

	//l1 += 5;
	list<Val>& operator+=(Val const& rhs);

	//l1[4]
	Val const& operator[](uint64_t i) const;

	Val& operator[](uint64_t i);

	list<Val>& operator--();
	list<Val>& operator--(int);
	
private:
	// ci metto i membri di classe
	node* m_front;
	node* m_back;
	
};
```

il codice di sopra lo immaginiamo all'interno di un file list.hpp che includiamo nel seguente

```cpp
#include "list.hpp"

template<typename Val>
list<Val>::list() : m_front(nullptr), m_back(nullptr){}

template<typename Val>
list<Val>::list(Val v) : list() {
	//m_back = m_front = new node {v, nullptr};
	push_front(v);
}

template<typename Val>
list<Val>::~list(){
	while(not empty()) pop_front();
}

template<typename Val>
list<Val>::node const * list<Val>::front() const {
	return m_front;
}

template<typename Val>
list<Val>::node const * list<Val>::back() const {
	return m_back;
}

template<typename Val>
void list<Val>::void push_front(Val v){
	if(empty()){
		m_front = m_back = new node{v, nullptr};
		return;
	}

	m_front = new node{v, m_front}
}

template<typename Val>
void list<Val>::void push_back(Val v){
	if(empty()){
		push_front()
		return;
	}
	m_back->next = new node{v,nullptr};
	m_back = m_back->next;
}

template<typename Val>
bool list<Val>::empty() const{
	return m_front == nullptr;
}

template<typename Val>
void list<Val>::pop_front(){
	if(not empty()){
		node* tmp = m_front;
		m_front = m_front->next;
		delete tmp;
		if(m_front == nullptr) m_back=nullptr;
	}
	
}

template<typename Val>
bool list<Val>::operator==(list<Val> const& rhs) const{
	auto ptr1 = front();
	auto ptr2 = rhs.front();
	while(ptr1 or ptr2){
		if((ptr1 and !ptr2) or (!ptr1 and ptr2) or (ptr1->val != ptr2->val))
			return false;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
}
```