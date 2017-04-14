#include <vector>

#ifndef TETELEK_H
#define TETELEK_H

bool LinearisKereses(const std::vector<int>& vect, bool beta(const int&), bool optimista, int& index);
bool LinearisKereses(const std::vector<std::vector<int> >& vect, bool beta(const std::vector<int>&), bool optimista, int& index);

#endif // TETELEK_H
