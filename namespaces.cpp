#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "namespaces.hpp"

using namespace std;

// Namespaces
namespace INFO
{
    string pieces = "kqrbnp";
    string colors = "wb";

    map<string, string> icons =
        {{"wk", "\u2654"},
         {"wq", "\u2655"},
         {"wr", "\u2656"},
         {"wb", "\u2657"},
         {"wn", "\u2658"},
         {"wp", "\u2659"},
         {"bk", "\u265A"},
         {"bq", "\u265B"},
         {"br", "\u265C"},
         {"bb", "\u265D"},
         {"bn", "\u265E"},
         {"bp", "\u265F"},
         {"wempty", " "},
         {"bempty", "\u2588"}};

    map<char, int> values =
        {{'k', 0},
         {'q', 9},
         {'r', 5},
         {'b', 3},
         {'n', 3},
         {'p', 1}};

    map<string, vector<vector<int>>> startPositions =
        {{"wk", {{4, 0}}},
         {"wq", {{3, 0}}},
         {"wr", {{0, 0}, {7, 0}}},
         {"wb", {{2, 0}, {5, 0}}},
         {"wn", {{1, 0}, {6, 0}}},
         {"wp", {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}}},
         {"bk", {{4, 7}}},
         {"bq", {{3, 7}}},
         {"br", {{0, 7}, {7, 7}}},
         {"bb", {{2, 7}, {5, 7}}},
         {"bn", {{1, 7}, {6, 7}}},
         {"bp", {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}, {7, 6}}}};

    string fileBorders[9] =
        {
            "\u2597\u2584\u2584\u2584\u2596\u2500\u2500\u2500\u2597\u2584\u2584\u2584\u2596\u2500\u2500\u2500\u2597\u2584\u2584\u2584\u2596\u2500\u2500\u2500\u2597\u2584\u2584\u2584\u2596\u2500\u2500\u2500\u2510",

            "\u259D\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u2596",
            "\u2597\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u2598",
            "\u259D\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u2596",
            "\u2597\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u2598",
            "\u259D\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u2596",
            "\u2597\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u2598",
            "\u259D\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u259E\u2580\u2580\u2580\u259A\u2584\u2584\u2584\u2596",

            "\u2514\u2500\u2500\u2500\u259D\u2580\u2580\u2580\u2598\u2500\u2500\u2500\u259D\u2580\u2580\u2580\u2598\u2500\u2500\u2500\u259D\u2580\u2580\u2580\u2598\u2500\u2500\u2500\u259D\u2580\u2580\u2580\u2598",
    };

};

namespace ID
{
    string files = "ABCDEFGH";
    // string ranks = "12345678";

    int fromFile(char file)
    {
        return files.find(toupper(file));
    }
    int fromRank(char rank)
    {
        return int(rank) - 1;
    }
    char toFile(int id)
    {
        return files[id];
    }
    char toRank(int id)
    {
        return to_string(id + 1).c_str()[0];
    }
    string coordsToFR(int idf, int idr)
    {
        return string(1, toFile(idf)) + string(1, toRank(idr));
    }
    vector<int> coordsFromFR(char file, char rank)
    {
        return {fromFile(file), fromRank(rank)};
    }
    vector<int> coordsFromFR(string filerank)
    {
        return {fromFile(filerank[0]), fromRank(filerank[1])};
    }
};
