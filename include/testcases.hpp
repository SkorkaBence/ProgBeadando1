#ifndef TESTCASES_HPP_INCLUDED
#define TESTCASES_HPP_INCLUDED

#include "Madar.h"
#include "Tetelek.h"
#include "Read.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Intervallum hossza 0-0", "0 varos 0 madar")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t0_0_0.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==false);
}

TEST_CASE("Intervallum hossza 0-3", "0 varos tobb madar")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t0_0_3.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==false);
}

TEST_CASE("Intervallum hossza 1-3", "1 varos tobb madar")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t1_1_3.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==false);
}

TEST_CASE("Intervallum hossza 1-4", "1 varos tobb madar")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t1_1_4.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==true);
}

TEST_CASE("Intervallum eleje 5-5", "elso varosban")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t2_5_5.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==true);
}

TEST_CASE("Intervallum vege 5-5", "utolso varosban")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t3_5_5.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==true);
}

TEST_CASE("Tetelre jellemzo - sehol", "sehol nincs")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t4_10_10.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==false);
}

TEST_CASE("Tetelre jellemzo - egy", "egy varosban van")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t4_10_10_2.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==true);
}

TEST_CASE("Tetelre jellemzo - mindenhol", "minden varosban van")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t4_10_10_3.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==true);
}

TEST_CASE("Madarak szama nulla", "tobb varos 0 madar")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t5_3_0.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==true);
}

TEST_CASE("Madarak szama 1 nincs", "tobb varos 1 madar")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t5_3_1.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==false);
}

TEST_CASE("Madarak szama 1 van", "tobb varos 1 madar")
{
    vector<vector<int> > madaradatok;
    vector<string> varosnevek;
    int n;

    FileOlasas("t5_4_1.txt", madaradatok, varosnevek);
    REQUIRE(EgyVarosbanMindenMadar(madaradatok,n)==true);
}

#endif // TESTCASES_HPP_INCLUDED
