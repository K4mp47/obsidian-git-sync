#include <iostream>
#include <functional>
#include <vector>
/**
 * Implementare la funzione map dato un vettore di interi ritorna un altro vettore 
 * dove è stato calcolato il fattoriale di ogni numero del vettore di partenza.
 * Essendo templetizzato, il codice è in grado di lavorare con qualsiasi tipo di dato.
 * La lambda è personalizzabile all'interno del main.
 * 
 * @author 89759
 * @date 2021/10/14
 * 
 * 
 * questi sono tutti iteratori per operare con la map
 * vedi la seconda funzione map per capire meglio
 * @param InputIterator from
 * @param InputIterator to
 * @param OutputIterator out
 * @param std::function<typename OutputIterator::value_type(typename InputIterator::value_type)> f 
 * 
 * @return vector<B> result
 * 
 * 
 * @example
 * std::vector<int> v = {1, 2, 3, 4, 5};
 * std::vector<int> result = map<int, int>(v, [](int x) {
 *    int res = 1;
 *   for(int i = 1; i <= x; i++){
 *      res *= i;
 *  }  
 * return res;
 * });
 * 
*/


template <class InputIterator, class OutputIterator>
void map(InputIterator from, InputIterator to, OutputIterator out, std::function<typename OutputIterator::value_type(typename InputIterator::value_type)> f)
{
    // Implementare la funzione map
    // ciclo for che scorre da from a to
    // salvo il risultato della funzione f in out ed incremento out
    // accedo tramite iteratori
    for (InputIterator it = from; it < to; ++it){
        *out = f(*it);
        ++out;
    }
}

template <class A, class B>
std::vector<B> map(const std::vector<A> &v, std::function<B(A)> f)
{
    std::vector<B> result(v.size());
    
    // InputIterator from to, OutputIterator
    // si possono benissimo rimuovere 
    typename std::vector<A>::input_iterator it = v.begin();
    typename std::vector<A>::input_iterator end = v.end();
    typename std::vector<B>::output_iterator it2 = result.begin();
   
    // chiamo la funzione map di cui sopra
    map(it, end, it2, f);

    return result;
}

/**
 * Ritorna il fattoriale di un numero
 * Stessi funzionamento della versione di cui sopra
 * solo che scritto in vanilla C++, senza lambda e std::function
 * 
*/
struct Factorial{
    int operator()(int x) const {
        int res = 1;
        for(int i = 1; i <= x; i++){
            res *= i;
        }
        return res;
    }
};


template <class InputIterator, class OutputIterator, class Functor>
void map(InputIterator from, InputIterator to, OutputIterator out, Functor f)
{
    // Implementare la funzione map
    // ciclo for che scorre da from a to
    // salvo il risultato della funzione f in out ed incremento out
    // accedo tramite iteratori
    for (InputIterator it = from; it < to; ++it){
        *out = f(*it);
        ++out;
    }
}

template <class A, class B, class C>
std::vector<B> map(const std::vector<A> &v, C f)
{
    std::vector<B> result(v.size());
    
    // InputIterator from to, OutputIterator
    typename std::vector<A>::const_iterator it = v.begin();
    typename std::vector<A>::const_iterator end = v.end();
    typename std::vector<B>::iterator it2 = result.begin();
   
    // chiamo la funzione map di cui sopra
    map(it, end, it2, f);

    return result;
}



int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result = map<int, int, Factorial>(v, Factorial());

    for(int x : result){
        std::cout << x << std::endl;
    }
    return 0;
}