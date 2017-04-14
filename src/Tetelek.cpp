#include "Tetelek.h"
#include <vector>

/*
    Altalanositott linearis kereses, mely a bemenettol fuggoen kepes optimista, es pesszimista
        linearis keresesre, eldontesre.
    Bemenet: Egy T osztalyokkal toltott vektor, amely az adatokat tarolja.
        Egy beta fuggveny, amely ha igaz erteket ad vissza, megallitja a keresest.
        Az optimista/pesszimista keresest eldonto kapcsolo
        Egy index, amely referencialis parameter, es egy talalat eseten ebbol nyerheto ki a talalt index
*/
template<class T>
bool linKerTemplate(const std::vector<T>& vect, bool beta(const T&), bool optimista, int& index) {
    bool l = optimista;

    int i = 0;
    while (l == optimista && i < vect.size()) {
        l = beta(vect[i]);
        index = i;
        i++;
    }

    return l;
}

/*
    Linearis kereses, ahol a T osztaly int
*/
bool LinearisKereses(const std::vector<int>& vect, bool beta(const int&), bool optimista, int& index) {
    return linKerTemplate(vect, beta, optimista, index);
}

/*
    Linearis kereses, ahol a T osztaly vector<int>
*/
bool LinearisKereses(const std::vector<std::vector<int> >& vect, bool beta(const std::vector<int>&), bool optimista, int& index) {
    return linKerTemplate(vect, beta, optimista, index);
}
