```cpp
class ListDL{
public:
	ListDL();
	ListDL(const ListDL& s);
	~ListDL();
	int size() const;
	void print() const;
	void prepend(int e);
	void append(int e);
	int& at(int pos);
	
	bool operator==(const& ListDL& l) const;
	const ListDL* operator=(const ListDL& l);
	ListDL operator+(const ListDL& l)

private:
	struct impl;
	impl* pimpl;
}
```

```cpp
#include "file_above.hpp"
#include <vector>

#define MAXE 10

struct ListDL::impl{
	vector<int> v;
	int head;
	int tail;
	int free;
}

ListDL::ListDL(){
	pimpl = new impl;
	pimpl->v.resize(MAXE*3);
	pimpl->head = -1;
	pimpl->tail = -1;
	pimpl->free = 0;

	for(int i=0; i < MAXE-1; i++){
		pimpl->v.at(i*3+2)=(i+1)*3;
	}

	pimpl->v.at((MAXE-1)*3+2) = -1;
}

ListDL::ListDL(const ListDL& s){
	pimpl = new impl;
	pimpl->v = s.pimpl->v;
	pimpl->head = s.pimpl->head;
	pimpl->tail = s.pimpl->tail;
	pimpl->free = s.pimpl->free;
}

// non bisogna fare pimpl = s.pimpl;
// questo genera errore perché copia anche i bit, punterebbero
// tutti e due alle stesse aree di memoria!!

ListDL::ListDL(const ListDL& s) {
	pimpl = new impl;
	*pimpl = *(s.pimpl);
	// in questo modo abbiamo in automatico i puntatori rifatti!!
}

ListDL::~ListDL(){
	delete pimpl;
}

void ListDL::prepend(int e){
	if(free != -1){ // abbiamo blocchi liberi
		int nuovo = pimpl->free;
		pimpl->free = pimpl->v.at(pimpl->free+2)
		pimpl->v.at(nuovo) = -1;
		pimpl->v.at(nuovo+1) = e;
		pimpl->v.at(nuovo+2) = pimpl->head;
		if(pmipl->head != -1)
			pimpl->v.at(head) = nuovo;
		pimpl->head = nuovo;
		if (pimpl->tail == -1) // caso di inserimento in lista vuota
			pimpl->tail = nuovo;
	}
}

void ListDL::print() const{
	for(int i=0; i<MAXE; i++){
		std::cout << i*3 << " : ";
		std::cout << "[" << pimpl->v.at(i) << ", " << pimpl->v.at(i*3+1) << ", " << pimpl->v.at(i*3+2) << "]" << std::endl;
	}
}

int& ListDl::at(int pos){
	int pc = pimpl->head;
	while (pc!=-1 && pos>0){
		pc = pimpl->v.at(pc+2);
		pos--;
	}
	if(pc!=-1)
		return pimpl->v.at(pc+1);
	else
		// bisognerebbe comunque gestirsi il caso di errore qua, questo
		// é un metodo provvisorio
		return pimpl->v.at(MAXE*3);
}

const ListDL& ListDL::operator=(const ListDL& l){
	if (this != &l) {
		pimpl->v = l.pimpl->v;
		pimpl->head = l.pimpl->head;
		pimpl->tail = l.pimpl->tail;
		pimpl->free = l.pimpl->free;
		
	}
	return *this;
}

bool ListDL& ListDL::operator==(const ListDL l) const {
	bool response = false;

	int pc1 = pimpl->head;
	int pc2 = l.pimpl->head;

	while(pc1!=-1 && pc2!=-1 && res){
		if(pimpl->v.at(pc1+1) != l.pimpl->v.at(pc2+1))
			res = false;
		else {
			pc1 = pimpl->v.at(pc1+1);
			pc2 = pimpl->v.at(pc2+1);
		}
	}
}

ListDL ListDL::operator+(const ListDL l) const {
	ListDL res=*this;

	int pc2 = l.pimpl->head;

	while(pc2!=-1){
		append(l.pimpl->v.at(pc2+1));
		pc2 = l.pimpl->v.at(pc2+1);
	}
}

int main(){
	ListDL l;

	l.print();
	
	l.prepend(15);
	l.prepend(20);
	l.append(25);

	l.at(1) = 200;

	l.print();
	
	return 0;
}
```

