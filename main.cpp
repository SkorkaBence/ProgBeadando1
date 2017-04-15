#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Madar.h"
#include "Tetelek.h"
#include "Read.h"

using namespace std;

/*
    Skorka Bence
    DOMJ1R
    skorka.bence@gmail.com
    2. csoport
*/

/*
    *************************************************************************
    *                                FONTOS                                 *
    *  A program norm�l futtat�s�hoz a TESTRUN makr� NE legyen defini�lva!  *
    * A tesztesetek futtat�s�hoz viszont a TESTRUN makr� LEGYEM defini�lva! *
    *   Ha a TESTRUN makr� nincs defini�lva, a program a feladatot fogja    *
    *        teljes�tani, ha a makr� defini�lva van, akkor lefuttatja       *
    *                            a teszteseteket                            *
    *************************************************************************
*/

// Tesztesetek futtat�s�hoz aktiv�lja ezt a makr�t:
//#define TESTRUN

#ifdef TESTRUN
#include "testcases.hpp"
#endif

#ifndef TESTRUN
bool menupont(int n) {
    return n >= 0 && n <= 2;
}

int main(int argc, char* argv[])
{
    std::vector<std::vector<int> > data;
    std::vector<std::string> townnames;

    if (argc > 1) {
        FileOlasas(argv[1], data, townnames);
    } else {
        cout << "Madaras feladat menu:" << endl;
        cout << "1: Betoltes standard inputrol" << endl;
        cout << "2: Betoltes filebol" << endl;
        cout << "0: Kilepes" << endl;

        int valaszottMenupont;

        valaszottMenupont = ReadInt(cin, "Valasztott menupont: ", "Hibas menupont, kerlek valassz egy letezo menupontot!\n", menupont);

        switch (valaszottMenupont) {
            case 0:
                return 0;
            case 1:
                Beolvasas(cin, data, townnames);
                break;
            case 2:
                string fn;
                do {
                    cout << "Filename: ";
                    cin >> fn;
                } while (!FileOlasas(fn, data, townnames));
                break;
        }
    }

    int index;
    if (EgyVarosbanMindenMadar(data, index)) {
        cout << townnames[index] << " varosban minden madar megtalalhato." << endl;
    } else {
        cout << "Nincs olyan varos, ahol minden madar megtalalhato";
    }

    return 0;
}

#endif
