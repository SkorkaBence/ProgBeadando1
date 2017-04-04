#include <vector>

#ifndef TETELEK_H
#define TETELEK_H

bool linKer(std::vector<int> vect, bool beta(int), bool optimista, int& index);
bool linKer(std::vector<std::vector<int> > vect, bool beta(std::vector<int>), bool optimista, int& index);

#endif // TETELEK_H
