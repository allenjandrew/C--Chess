#ifndef CHESS_NAMESPACES
#define CHESS_NAMESPACES

#include <string>
#include <map>
#include <vector>

namespace INFO
{
    extern std::string pieces;
    extern std::string colors;
    extern std::map<std::string, std::string> icons;
    extern std::map<char, int> values;
    extern std::map<std::string, std::vector<std::vector<int>>> startPositions;
    extern std::string fileBorders[9];
}

namespace ID
{
    extern std::string files;

    int fromFile(char file);
    int fromRank(char rank);
    char toFile(int id);
    char toRank(int id);
    std::string coordsToFR(int idf, int idr);
    std::vector<int> coordsFromFR(char file, char rank);
    std::vector<int> coordsFromFR(std::string filerank);

}

#endif // CHESS_NAMESPACES