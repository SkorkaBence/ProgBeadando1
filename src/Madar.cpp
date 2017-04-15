#include "Madar.h"
#include "Tetelek.h"

/*
    Ez a fuggveny a beta fuggvenye a minenElofordul linearis keresesnek.
*/
bool nemnulla(const int& n) {
    return n != 0;
}

/*
    Ez a fuggveny a beta fuggvenye az EgyVarosbanMindenMadar linerais keresesnek
    Feladat: Az ertekek kozott van e nulla
    Megoldas: Optimista linearis keresessel, van e olyan ertek, ami nulla.
*/
bool MinenElofordul(const std::vector<int>& vc) {
    int ind;
    return LinearisKereses(vc, nemnulla, true, ind);
}

/*
    Feladat: Keressunk olyan varost, ahol minden madarbol van legalabb egy.
    Megoldas: Pesszimista linerais keresessel, olyan sort keres a matrixban,
        amelyre teljesul a minenElofordul tulajdonsag.
*/
bool EgyVarosbanMindenMadar(const std::vector<std::vector<int> >& adatok, int& index) {
    return LinearisKereses(adatok, MinenElofordul, false, index);
}
/*
    Feladat: Az inp input sreamet felhasznalva feltolti a tn vektort a varos
        nevekkel, es a matrix matrixot pedig a madar adatokkal.
        Minden sor egy varos, es a soron belul megtalalhatoak az adott varosban
        levo egyes madarfajok egyedeinek szama.
*/
void Beolvasas(std::istream& inp, std::vector<std::vector<int> >& matrix, std::vector<std::string>& tn, bool kiir) {
    int w, h;

    w = ReadInt(inp, "Varosok szama: ", "Hibas ertek!\n", nat, !kiir);
    if (kiir) {
        std::cout << w << std::endl;
    }

    h = ReadInt(inp, "Madarfajok szama: ", "Hibas ertek!\n", nat, !kiir);
    if (kiir) {
        std::cout << h << std::endl;
    }

    matrix.resize(w);
    tn.resize(w);

    inp.clear();
    inp.ignore(1000, '\n');

    for (int x = 0; x < w; x++) {
        matrix[x].resize(h);
        std::cout << x + 1 << ". varos neve: ";
        getline(inp, tn[x]);
        if (kiir) {
            std::cout << tn[x] << std::endl;
        }
    }

    for (int x = 0; x < w; x++) {
        std::cout << "--- " << tn[x] << " madarai ---" << std::endl;
        for (int y = 0; y < h; y++) {
            matrix[x][y] = ReadInt(inp, toString(y+1) + ". szamu madarfaj darabja: ", "Hibas ertek!\n", nat, !kiir);
            if (kiir) {
                std::cout << matrix[x][y] << std::endl;
            }
        }
    }
}
void Beolvasas(std::istream& inp, std::vector<std::vector<int> >& matrix, std::vector<std::string>& tn) {
    Beolvasas(inp, matrix, tn, false);
}

/*
    Feladat: Megkiserli egy file megnyitasat, es ha sikerult, akkor abbol beolvassa az adatokat.
*/
bool FileOlasas(const std::string& filename, std::vector<std::vector<int> >& matrix, std::vector<std::string>& tn) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Nem letezo file: " << filename << std::endl;
    } else {
        Beolvasas(file, matrix, tn, true);
    }
    return file.is_open();
}
