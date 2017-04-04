#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Tetelek.h"

using namespace std;

enum Exceptions {
    WRONG_INPUT, NEGATIVE_SIZE, NEGATIVE_NUMBER_OF_BIRDS
};

template<class T>
void readMatrix(istream& inp, vector<vector<T> >& matrix);
template<class T>
void printMatrix(ostream& out, const vector<vector<T> >& matrix);

bool nulla(int i) {
    return i == 0;
}

bool minenElofordul(vector<int> vc) {
    int ind;
    return linKer(vc, nulla, true, ind);
}

int main()
{
    ifstream file("adat.txt");

    if (!file.is_open()) {
        cout << "NF";
        return 0;
    }

    vector<vector<int> > data;

    try {
        readMatrix(file, data);
    } catch (Exceptions e) {
        switch (e) {
            case WRONG_INPUT:
                cout << "A bemenetnek egesz szamnak kell lennie!" << endl;
                exit(0);
            case NEGATIVE_SIZE:
                cout << "Az adatok mennyisege nem lehet negativ!" << endl;
                exit(0);
            case NEGATIVE_NUMBER_OF_BIRDS:
                cout << "Nem lehet negativ szamu madar egy varosban!" << endl;
                exit(0);
        }
    }

    int index = 0;
    if (linKer(data, minenElofordul, false, index)) {
        cout << "A(z) " << index+1 << ". varosban minden madar megtalalhato!";
    } else {
        cout << "Nincs olyan varos, ahol minden madar megtalalhato";
    }

    return 0;
}

template<class T>
void readMatrix(istream& inp, vector<vector<T> >& matrix) {
    int w, h;
    inp >> w;
    if (inp.fail()) {
        throw WRONG_INPUT;
    }
    inp >> h;
    if (inp.fail()) {
        throw WRONG_INPUT;
    }

    if (w < 0 || h < 0) {
        throw NEGATIVE_SIZE;
    }

    matrix.resize(w);

    for (int x = 0; x < w; x++) {
        matrix[x].resize(h);
        for (int y = 0; y < h; y++) {
            inp >> matrix[x][y];
            if (inp.fail()) {
                throw WRONG_INPUT;
            }
            if (matrix[x][y] < 0) {
                throw NEGATIVE_NUMBER_OF_BIRDS;
            }
        }
    }
}

template<class T>
void printMatrix(ostream& out, const vector<vector<T> >& matrix) {
    out << matrix.size() << std::endl;

    for (int x = 0; x < matrix.size(); x++) {
        out << "(" << x << "|" << matrix[x].size() << ")";
        for (int y = 0; y < matrix[x].size(); y++) {
            out << " " << matrix[x][y];
        }
        out << std::endl;
    }
}
