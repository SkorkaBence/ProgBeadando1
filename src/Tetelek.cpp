#include "Tetelek.h"
#include <vector>

template<class T>
bool linKerTemplate(std::vector<T> vect, bool beta(T), bool optimista, int& index) {
    bool l = optimista;

    int i = 0;
    while (l == optimista && i < vect.size()) {
        if (beta(vect[i])) {
            l = !l;
            index = i;
        }
        i++;
    }

    return l;
}

bool linKer(std::vector<int> vect, bool beta(int), bool optimista, int& index) {
    return linKerTemplate(vect, beta, optimista, index);
}

bool linKer(std::vector<std::vector<int> > vect, bool beta(std::vector<int>), bool optimista, int& index) {
    return linKerTemplate(vect, beta, optimista, index);
}
