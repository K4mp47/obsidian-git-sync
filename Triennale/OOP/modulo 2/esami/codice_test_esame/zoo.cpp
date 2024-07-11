#include <iostream>

class animal
{

protected: // accessibile solo dalle classi che estendono animal
    int weight;
    int speed;

public:
    animal(int w, int s) : weight(w), speed(s) {} // constructor

    animal(const animal &a) : weight(a.weight), speed(a.speed) {} // copy constructor

    int getWeight() const { return this->weight; } // this corrisponde ad un pointer nelle classi cpp

    const int &weight2() const { return weight; } // const per evitare modifiche al valore ritornato, non permette l'assegnamento

    int &weight2() { return weight; } // in realtà ritorna una copia della reference permette l'assegnamento

    virtual void eat(const animal &a) // attributo virtual per permettere l'override, virtual perché viene messo in virtual table
    {
        weight2() += a.getWeight();
    }
};

class dog : public animal // extend animal
{
private:
    bool isGoodBoy;

public:
    dog(int w, int s) : animal(w, s) {} // super constructor

    dog(const dog &d) : animal(d) {} // copy constructor

    void eat(const animal &a) // override del metodo eat
    {
        weight2() += a.getWeight() * 2; // getWeight obbligatoria perché a.weight non è accessibile
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    animal *a = new animal(10, 10); // allocazione su heap
    animal a1(10, 10);              // allocazione su stack
    dog d(10, 10);
    dog d1(d);
    d1.eat(d);
    std::cout << d1.getWeight() << std::endl;
    return 0;
}
