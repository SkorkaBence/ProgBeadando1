#include <vector>
#include <iostream>
#include <fstream>
#include "Read.h"

#ifndef MADAR_H
#define MADAR_H

bool EgyVarosbanMindenMadar(const std::vector<std::vector<int> >& adatok, int& index);
bool FileOlasas(const std::string& filename, std::vector<std::vector<int> >& matrix, std::vector<std::string>& tn);
void Beolvasas(std::istream& inp, std::vector<std::vector<int> >& matrix, std::vector<std::string>& tn);

#endif // MADAR_H
