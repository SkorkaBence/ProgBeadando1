#include <iostream>
#include <sstream>

#ifndef READ_H
#define READ_H

struct ReadException {
    std::string message;
};

std::string toString(const int& item);

bool all(int n);
bool nat(int n);

int ReadInt(std::istream& input, const std::string bekeroFelirat, const std::string hibaUzenet, bool feltetel(int), const bool ismetles);
int ReadInt(std::istream& input, const std::string bekeroFelirat, const std::string hibaUzenet, bool feltetel(int));
int ReadInt(std::istream& input, const std::string bekeroFelirat, bool feltetel(int));
int ReadInt(std::istream& input, const std::string bekeroFelirat, const std::string hibaUzenet);
int ReadInt(std::istream& input, const std::string bekeroFelirat);

#endif // READ_H
