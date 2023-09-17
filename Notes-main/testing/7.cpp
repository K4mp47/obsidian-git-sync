#include<iostream>
#include<string>


class Number{
  public:
    Number();
    Number(unsigned int m);
    Number(const Number& l);
    Number(std::string s);
    ~Number();

    void print() const;

    Number operator+(const Number& x) const;
    Number operator*(const Number& x) const;
    bool operator==(const Number& x) const;
    bool operator!=(const Number& x) const;
    Number& operator=(const Number& x);


  private:
    //Non modificare
    struct Cell{
      char info;
      Cell* next;
    };

    typedef Cell* List;

    List n = nullptr;
    List sum(List l1, List l2, char carry) const;
    void print_rec(List l) const;

    
    //Parte modificabile (ma attenzione: ora è progettata per guidarvi)
    void destroy(List h);
    List convert(unsigned int m);

    //List copy(const List pc);
    bool equal(List l1, List l2) const;
};

//Costruttore di default, 0 e' codificato con la lista vuota
Number::Number() {
  n=nullptr;
}

//converte un unsigned int nella lista richiesta
Number::Number(unsigned int m) {
  n = convert(m);
}

//studia questa funzione per comprendere completamente la rappresentazione nel numero
//e' un bell'esempio di ricorsione
Number::List Number::convert(unsigned int m) {
  if (m==0)
    return nullptr;
  else {
    List pc = new Cell;
    pc->info = m%10;
    pc->next = convert(m/10);
    return pc;
  }
}

//stampa la lista: siccome le cifre meno significative sono in testa, devo stampare al contrario
void Number::print() const {
  if (n==nullptr) 
    std::cout<<"0";
  else
    print_rec(n);
}

//parte ricorsiva della stampa
void Number::print_rec(List l) const {
  if (l) {
    print_rec(l->next);
    std::cout<<static_cast<char>(l->info+'0'); //Ecco il type casting explicito in C++
  }
}

//distruttore
Number::~Number() {
  destroy(n);
}

//funzione di disruzione ricorsiva
void Number::destroy(List h) {
  if (h) {
    destroy(h->next);
    delete(h);
  }
}

//primo metodo da implementare: dato un numero codificato con una stringa
//scritto in modo che la cifra piu' significativa e' nella prima posizione
//generare un Number. Attenzione non fare la conversione string->int->list
//perche' potresti avere errori di overflow
Number::Number(std::string s) {
  n = nullptr;
  for(size_t i=0; i < s.size(); i++){
    n = new Cell{static_cast<char>(s[i] - '0'), n}; 
  }
  //std::cout << static_cast<int>(n->info) << static_cast<int>(n->next->info) << std::endl << std::endl;
}

//secondo metodo da implementare: copy constructor
//consigliato far uso della funzione privata ricorsiva copy
//potrebbe esserti utile anche per l'assegnamento!
Number::Number(const Number&x) {
  if (this!=&x) {
    n = nullptr;
    Cell* temp = x.n;
    if(temp)
        n = new Cell{temp->info, nullptr};
    temp = temp->next;
    Cell* app = n;
    while(temp){
      app->next = new Cell{temp->info, nullptr};
      app = app->next;
      temp = temp->next;
    }
  } 
}


//Number::List Number::copy(const List pc) {
//se preferisci non usarla, cancellala anche dall'intestazione
//}


//l'operatore + non va modificato. Deve utilizzare il meotodo sum come indicato
Number Number::operator+(const Number& x) const {
  Number res;
  std::cout << x.n->info << std::endl;
  res.n = sum(x.n, n, 0);
  Cell* temp = res.n;
  while(temp){
    std::cout << static_cast<int>(temp->info);
    temp = temp->next;
  }
  std::cout << std::endl;
  return res;
}

//Questa funzione deve essere ricorsiva. Implementala con cura. Ricorda
//che l'ultimo carry potrebbe essere diverso da 0
Number::List Number::sum(List l1, List l2, char carry) const {
  if(l1 == nullptr && l2 == nullptr && carry == 0){
      return nullptr;
  }
  //if(temp->next)
   // std::cout << static_cast<int>(temp->info) << "+" << static_cast<int>(temp->next->info); 
  //std::cout << std::endl;

  if(!l1){
    l1 = new Cell{0, nullptr};
  }
    //std::cout << static_cast<int>(sum1)<< std::endl;
  if(!l2){
    l2 = new Cell{0, nullptr}; 
    //std::cout << static_cast<int>(sum1)<< std::endl;
  }
  int sum1 = carry + l1->info + l2->info;
  int car = sum1 / 10;

  //std::cout << static_cast<int>(sum1)<< std::endl;
  sum1 %= 10;

  //std::cout << static_cast<int>(sum1)<< std::endl;
  return new Cell{static_cast<char>(sum1) , sum(l1->next, l2->next, static_cast<char>(car))};
  //std::cout << std::endl;
}
//operatore di assegnamento. Segui la traccia
Number& Number::operator=(const Number& x) {
  if (this!=&x) {
    n = nullptr;
    Cell* temp = x.n;
    if(temp)
        n = new Cell{temp->info, nullptr};
    temp = temp->next;
    Cell* app = n;
    while(temp){
      app->next = new Cell{temp->info, nullptr};
      app = app->next;
      temp = temp->next;
    }
  }
  return *this;
}


//La seguente funzione puo' essere modificata, ma e'
//consigliato usare la equal sviluppata ricorsivamente
bool Number::operator==(const Number& x) const{
  return equal(x.n, n);
}

//Da sviluppare
bool Number::equal(List l1, List l2) const {
  Cell* temp1 = l1;
  Cell* temp2 = l2;
  while(temp1 && temp2 && temp1->info == temp2->info){
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  if(temp1 || temp2){
    return false;
  } else if (temp1 && temp2){
    if(temp1->info != temp2->info){
      return false;
    }
  }
  return true;
}

//Metodo velore per implementare il != 
bool Number::operator!=(const Number& x) const{
  return !(*this==x);
}

//Fare il prodotto x*y significa sommare x+x+x+..+x (y volte...)
//non il modo piu' efficiente, ma il piu' facile
//Ricorda che tutte le operazioni vanno fatte coi numbers!
Number Number::operator*(const Number& x) const{
  Number res(0);
  return res;

}
Number opera(Number x, Number y) {
  //return x+y;
  return x+y;
}


int main() {
  std::string s1, s2;
  std::cin>>s1;
  std::cin>>s2;
  Number n1(s1), n2(s2);
  //Number n3=24593;
  Number n3 = opera(n1, n2);
  
  n1.print(); 
  std::cout<<std::endl;
  n2.print();
  std::cout<<std::endl;
  n3.print();
  std::cout<<std::endl;
  if (n1==n2) 
    std::cout<<"Numeri uguali inseriti"<<std::endl;
 

  return 0;
}


