#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Madar.h"
#include "Tetelek.h"
#include "Read.h"

using namespace std;

bool menupont(int n) {
    return n >= 0 && n <= 2;
}

int main(int argc, char* argv[])
{
    std::vector<std::vector<int> > data;
    std::vector<std::string> townnames;

    if (argc > 1) {
        FileOlasas(argv[2], data, townnames);
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
