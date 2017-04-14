#include "Read.h"

std::string toString(const int& item) {
    std::stringstream ss;
    ss << item;
    return ss.str();
}

bool all(int n) {
    return true;
}
bool nat(int n) {
    return n >= 0;
}
/*
    Tobbfunkcios Integer beolvasas fuggveny.
    Parameterkent megkapja az input istream -et, amelyrol olvas adatokat,
    a bekeroFelirat, amit kiir a beolvasas elott, a hibaUzenet, amelyet kiir
    egy hibas bemenet eseten, a feltetel fuggvenyt, amivel hitelesiteni lehet
    a kapott adatot, es az ismetles kapcsolot, amely a fuggveny mukodeset
    modositja:
        - Ha az ismetles = true:
            Hibas input eseten megismetli a bekerest
            Ajanlott felhasznalas: Console beolvasas eseten
        - Ha az ismetles = false:
            Hibas input eseten egy ReadException hibat visszadob, amely
            tartalmazza a hiba okat: Beolvasasi hiba, vagy
            feltetelnek nem megfelelo ertek erkezett.
*/
int ReadInt(std::istream& input, const std::string bekeroFelirat, const std::string hibaUzenet, bool feltetel(int), const bool ismetles) {
    int n;
    bool ReadError;
    bool ValidNumber = false;
    do {
        std::cout << bekeroFelirat;
        input >> n;
        ReadError = input.fail();
        if (!ReadError) {
            ValidNumber = feltetel(n);
        }
        if (ReadError || !ValidNumber) {
            if (ismetles) {
                input.clear();
                input.ignore(1000, '\n');
                std::cout << hibaUzenet;
            } else {
                ReadException ex;
                if (ReadError) {
                    ex.message = "Beolvasasi Hiba";
                } else if (!ValidNumber) {
                    ex.message = "A szam nem felel meg a felteteleknek!";
                }
                throw ex;
            }
        }
    } while (ReadError || !ValidNumber);
    return n;
}

/*
    ReadInt altalanositott ismetlessel: felteteles console olvasashoz ajanlott
*/
int ReadInt(std::istream& input, const std::string bekeroFelirat, const std::string hibaUzenet, bool feltetel(int)) {
    return ReadInt(input, bekeroFelirat, hibaUzenet, feltetel, true);
}

/*
    ReadInt hibauzenet es ismetles nelkul: felteteles file olvasashoz ajanlott
*/
int ReadInt(std::istream& input, const std::string bekeroFelirat, bool feltetel(int)) {
    return ReadInt(input, bekeroFelirat, "", feltetel, false);
}

/*
    ReadInt barmely egesz szamra: feltetel nelkuli console olvasashoz ajanlott
*/
int ReadInt(std::istream& input, const std::string bekeroFelirat, const std::string hibaUzenet) {
    return ReadInt(input, bekeroFelirat, hibaUzenet, all, true);
}

/*
    ReadInt hiba nelkul, barmely egesz szamra: feltetel nelkuli file olvasashoz ajanlott
*/
int ReadInt(std::istream& input, const std::string bekeroFelirat) {
    return ReadInt(input, bekeroFelirat, "", all, false);
}
