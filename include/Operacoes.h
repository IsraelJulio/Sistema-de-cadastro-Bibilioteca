#ifndef Operacoes_H
#define Operacoes_H
#include <string>
#include<vector>
#include <iterator>
using namespace std;

class Operacoes{

    private:

    public:
    template<typename it, typename valueT, typename outIt>
    static void split(it first, it last, const valueT& e, outIt&& o) {
    auto next = first;
    while ( next != last ) {
        next = std::find(first, last, e);
        *o++ = { first, next };
        first = next;
        first++;
    }
}
};

#endif