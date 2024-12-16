#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "classes.cpp"
#include "namespaces.hpp"

using namespace std;

// Function declarations
// string getIcon(const char type, const char color);

// Main!!
int main()
{
    cout << endl;

    // cout << "Is this working? " << INFO::icons.at("wk") << INFO::icons.at("bk") << endl;
    // char rank = '3';
    // char file = 'B';
    // int idr = ID::fromRank(rank);
    // int idf = ID::fromFile(file);
    // cout << "Rank " << rank << " has index " << idr << endl;
    // cout << "File " << file << " has index " << idf << endl;
    // idr = 4;
    // idf = 7;
    // rank = ID::toRank(idr);
    // file = ID::toFile(idf);
    // cout << "ID " << idr << " means rank " << rank << endl;
    // cout << "ID " << idf << " means file " << file << endl;
    // char c = cin.get();
    // cout << "You typed: " << c << endl;

    Board board;

    // board.displayBoard();

    board.play();
}

// Function definitions

// string getIcon(const char type, const char color)
// {
//     if (color == 'w')
//     {
//         if (type == 'k')
//             return icons.wk;
//         if (type == 'q')
//             return icons.wq;
//         if (type == 'r')
//             return icons.wr;
//         if (type == 'b')
//             return icons.wb;
//         if (type == 'n')
//             return icons.wn;
//         if (type == 'p')
//             return icons.wp;
//     }
//     else if (color == 'b')
//     {
//         if (type == 'k')
//             return icons.bk;
//         if (type == 'q')
//             return icons.bq;
//         if (type == 'r')
//             return icons.br;
//         if (type == 'b')
//             return icons.bb;
//         if (type == 'n')
//             return icons.bn;
//         if (type == 'p')
//             return icons.bp;
//     }
//     return ""; // Return an empty string if no match found
// }

// ChessBoard grid nums:
// Files A through H: 0-7; 0-3 is queenside, 4-7 is kingside
// Ranks 1 through 8: 0-7; 0 is white, 7 is black
