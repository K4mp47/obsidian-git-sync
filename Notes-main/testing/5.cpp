#include<iostream>
#include<string>

using namespace std;

/*Classe lista di stringhe ordinate alfabeticamente in modo
 * crescente. La lista e' doppiamente concatenata*/

class ListStrings{
public:
  ListStrings();
  ListStrings(ListStrings&& ls);
  ~ListStrings();
  void print_forward() const;
  void print_reversed() const;
  void add(const string& s);
  ListStrings& operator=(const ListStrings& ls);
  ListStrings operator+(const ListStrings& ls) const;
private:
  struct Cell{
    string info;
    Cell* next;
    Cell* prev;
  };
  Cell* head; //puntatore alla prima cella
  Cell* tail; //puntatore all'ultima cella
};


//Default constructor
ListStrings::ListStrings() {
  head = nullptr;
  tail = nullptr;
}


//Move constructor
ListStrings::ListStrings(ListStrings&& ls) {
  std::cout<<"Move costructor"<<endl;
  head = ls.head;
  tail = ls.tail;
  ls.head = nullptr;
  ls.tail = nullptr;
}

//stampa da head a tail
void ListStrings::print_forward() const{
  Cell* ptr=head;
  while (ptr) {
    cout<<ptr->info<<endl;
    ptr = ptr->next;
  }
}

//stampa da tail a head
void ListStrings::print_reversed() const{
  Cell* ptr=tail;
  while(ptr) {
    cout<<ptr->info<<endl;
    ptr=ptr->prev;
  }
}



//Destructor: 
ListStrings::~ListStrings() {
  while(head){
    Cell* d = head;
    head = head->next;
    delete d;
  }
  tail = nullptr;
}


void ListStrings::add(const string& s) {
  //Scrivi qui il tuo codice Esercizio 1
  if(head == nullptr){
    Cell* firstnode = new Cell();
    firstnode->info = s;
    firstnode->next = nullptr;
    firstnode->prev = nullptr;
    head = firstnode;
    tail = head;
    return;
  }
  if (head->info > s){
    Cell* nextnode = new Cell();
    nextnode->info = s;
    nextnode->next = head;
    nextnode->prev = nullptr;
    head->prev = nextnode;
    head = nextnode;
    return;
  } 
  Cell* node = head;
  Cell* bef  = head;
  while(node != nullptr && node->info < s){
    bef = node;
    node = node->next;
  }
  node = head;
  while(node->next != nullptr && node->next->info < s){
    node = node->next;
  }
  if(node->next != nullptr){
    Cell* nextnode = new Cell();
    nextnode->info = s;
    nextnode->next = node->next;
    nextnode->prev = bef;
    nextnode->next->prev = nextnode;
    node->next = nextnode;
  } else {
    Cell* nextnode = new Cell();
    nextnode->info = s;
    nextnode->next = nullptr;
    nextnode->prev = bef;
    node->next = nextnode;
    tail = node->next;
  }
}
       
ListStrings& ListStrings::operator=(const ListStrings& ls) {
   //Scrivi qui il tuo codice Esercizio 2
  if(ls.head){
    Cell* index = ls.head;
    while(this->head){
        Cell* p = this->head;
        this->head = this->head->next;
        delete p;
    }
    this->tail = nullptr;
    Cell* newnode = new Cell();
    newnode->info = index->info;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    this->head = newnode;
    this->tail = newnode;
    Cell* copyindex = this->head;
    index = index->next;
    while(index){
        Cell* nextnode = new Cell();
        nextnode->info = index->info;
        nextnode->next = nullptr;
        nextnode->prev = copyindex;
        copyindex->next = nextnode;
        copyindex = copyindex->next;
        this->tail = copyindex;
        index = index->next;
    }
  } else {
    while(this->head){
        Cell* p = this->head;
        this->head = this->head->next;
        delete p;
    }
    this->tail = nullptr;
  }
  return *this;
}


ListStrings ListStrings::operator+(const ListStrings& ls) const {
   //Scrivi qui il tuo codice Esercizio 3
  ListStrings res;
  if(this->head){
    Cell* index = this->head;
    Cell* newnode = new Cell();
    newnode->info = index->info;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    res.head = newnode;
    res.tail = newnode;
    Cell* copyindex = res.head;
    index = index->next;
    while(index){
        Cell* nextnode = new Cell();
        nextnode->info = index->info;
        nextnode->next = nullptr;
        nextnode->prev = copyindex;
        copyindex->next = nextnode;
        copyindex = copyindex->next;
        res.tail = copyindex;
        index = index->next;
    }
  } 
  if(ls.head != nullptr){
    Cell* addnode = nullptr;
    if(res.head == nullptr){
      Cell* firstnode = new Cell();
      firstnode->info = ls.head->info;
      firstnode->next = nullptr;
      firstnode->prev = nullptr;
      res.head = firstnode;
      res.tail = head;
      addnode = ls.head->next;
    } else {
      addnode = ls.head;
    }
    while(addnode){
        if (res.head->info > addnode->info && addnode){
            Cell* nextnode = new Cell();
            nextnode->info = addnode->info;
            nextnode->next = res.head;
            nextnode->prev = nullptr;
            res.head->prev = nextnode;
            res.head = nextnode;
        } else {
            Cell* node = res.head;
            Cell* bef  = res.head;
            while(node != nullptr && node->info < addnode->info){
                bef = node;
                node = node->next;
            }
            node = res.head;
            while(node->next != nullptr && node->next->info < addnode->info){
                node = node->next;
            }
            if(node->next != nullptr){
                Cell* nextnode = new Cell();
                nextnode->info = addnode->info;
                nextnode->next = node->next;
                nextnode->prev = bef;
                nextnode->next->prev = nextnode;
                node->next = nextnode;
            } else {
                Cell* nextnode = new Cell();
                nextnode->info = addnode->info;
                nextnode->next = nullptr;
                nextnode->prev = bef;
                node->next = nextnode;
                res.tail = node->next;
            }
        }
        addnode = addnode->next;
    }
  }
  return res;
}

int main() {
  int n;
  string s;
  ListStrings ls;

  cin >> n;
  for (; n>0; n--) {
    cin>>s;
    ls.add(s);
  }
  cout<<endl;
  ls.print_forward();
  cout<<endl;
  ls.print_reversed();
  return 0;
}

