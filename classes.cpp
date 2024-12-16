#include <iostream>
#include <string>
#include <vector>
// #include <map>
#include "namespaces.hpp"

using namespace std;

// Class definitions
class Piece
{
public:
    char color;
    char type;
    int f;
    int r;
    int value;
    bool isWhite;
    bool isAlive;
    vector<vector<int>> validMoves;

public:
    string icon;
    Piece() : type('e'), f(0), r(0), isWhite(true), isAlive(true)
    {
        this->color = 'w';
        this->icon = INFO::icons.at("wempty");
        this->value = 0;
    }

    Piece(char type, int f, int r, bool isWhite, bool isAlive)
    {
        this->type = (INFO::pieces.find(type) == string::npos) ? 'p' : type;
        this->f = f;
        this->r = r;
        this->isWhite = isWhite;
        this->isAlive = isAlive;

        this->color = isWhite ? 'w' : 'b';
        this->icon = INFO::icons.at({color, type});
        this->value = INFO::values.at(type);

        findValidMoves();
    }

    void moveTo(int idf, int idr)
    {
        this->f = idf;
        this->r = idr;
        findValidMoves();
    }

    void moveTo(char file, char rank)
    {
        this->f = ID::fromFile(file);
        this->r = ID::fromRank(rank);
        findValidMoves();
    }

    void moveTo(string filerank)
    {
        vector<int> coords = ID::coordsFromFR(filerank);
        this->f = coords[0];
        this->r = coords[1];
        findValidMoves();
    }

    virtual void findValidMoves()
    {
        vector<vector<int>> newValidMoves;
        int temp = this->isWhite ? 1 : -1;
        vector<int> validMove = {this->f, this->r + temp};
        newValidMoves.push_back(validMove);
        if (this->r == (this->isWhite ? 1 : 6))
        {
            vector<int> validMove = {this->f, this->r + (temp * 2)};
            newValidMoves.push_back(validMove);
        }
        this->validMoves = newValidMoves;
    }

    void kill()
    {
        this->isAlive = false;
        delete this;
    }
};

class King : public Piece
{
public:
    string type;
    King(int f, int r, bool isWhite) : Piece('k', f, r, isWhite, true)
    {
    }
    void findValidMoves()
    {
        vector<vector<int>> newValidMoves;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (this->f + i >= 0 && this->r + j >= 0 && this->f + i < 8 && this->r + j < 8)
                {
                    vector<int> validMove = {this->f + i, this->r + j};
                    newValidMoves.push_back(validMove);
                }
            }
        }
        this->validMoves = newValidMoves;
    }
};

class Square
{
public:
    Piece *piece;
    bool isOccupied;
    bool isWhite;
    int f;
    int r;

    Square()
    {
        this->isOccupied = false;
        this->isWhite = false;
        // this->piece = Piece();
    }

    void setPosition(int f, int r)
    {
        this->f = f;
        this->r = r;
        setIsWhite((f + r) % 2 == 1);
    }

    void addPiece(Piece &piece)
    {
        // Piece oldPiece = this->piece;
        this->piece = &piece;
        // oldPiece.kill();
        this->isOccupied = true;
    }

    void removePiece()
    {
        if (!this->isOccupied)
        {
            return;
        }

        int rawr;
        cout << "inside removepiece" << endl;
        cin >> rawr;

        // Piece oldPiece = *this->piece;

        cout << "2nd" << endl;
        cin >> rawr;

        // Piece emptyPiece;
        this->piece = nullptr; // = emptyPiece;
        // oldPiece.kill();

        cout << "3rd" << endl;
        cin >> rawr;

        this->isOccupied = false;

        cout << "done here" << endl;
        cin >> rawr;
    }

    void setIsWhite(bool isWhite)
    {
        this->isWhite = isWhite;
    }

    void setColor(char color)
    {
        this->isWhite = color == 'w';
    }

    bool IsWhite()
    {
        return this->isWhite;
    }

    char getColor()
    {
        return this->isWhite ? 'w' : 'b';
    }

    Piece *getPiece()
    {
        return this->piece;
    }

    string asDisplay()
    {
        string block = this->isWhite ? " " : "\u2588";
        string icon = this->isOccupied ? this->piece->icon : INFO::icons.at(string(1, getColor()) + "empty");
        return block + icon + block;
    }
};

class Board
{
public:
    Square grid[8][8];
    bool isWhitesTurn;
    int turnNumber;
    vector<string> moves[2];
    string lastWhiteMove;
    vector<Piece> pieces[2];

    struct
    {
        char pieceType;
        char idingfile;
        char idingrank;
        char takes;
        char file;
        char rank;
        char check;
        bool isCastling;
        bool castleKingside;
    } move;

    Board()
    {
        this->isWhitesTurn = true;
        this->turnNumber = 1;

        for (int f = 0; f < 8; f++)
        {
            for (int r = 0; r < 8; r++)
            {
                this->grid[f][r].setPosition(f, r);
            }
        }

        for (auto piecePos : INFO::startPositions)
        {
            for (auto coords : piecePos.second)
            {
                int worb = piecePos.first[0] == 'w' ? 0 : 1;
                // vector<Piece> *piecesvectorptr = &this->pieces[piecePos.first[0] == 'w' ? 0 : 1];
                // cout << piecePos.first[1] << endl;
                Piece piece = Piece(piecePos.first[1], coords[0], coords[1], piecePos.first[0] == 'w', true);
                this->pieces[worb].push_back(piece);

                // cout << &piece << endl;
                // cout << &(*piecesvectorptr->end()) << endl;
                this->grid[coords[0]][coords[1]].addPiece(*this->pieces[worb].end());
                this->pieces[piecePos.first[0] == 'w' ? 0 : 1].push_back(piece);
            };
        };
    };

    void displayBoard()
    {
        cout << endl;
        print_ranks_line();

        for (int f = 0; f < 8; f++)
        {
            cout << "  " << INFO::fileBorders[f] << endl
                 << ID::toFile(f) << " ";
            bool blackStart = true;

            for (int r = 0; r < 8; r++)
            {
                if (f % 2 == 1 && r == 0)
                {
                    cout << "\u2502" << this->grid[f][r].asDisplay();
                }
                else
                {
                    cout << (blackStart ? "\u2590" : "\u258C") << this->grid[f][r].asDisplay();
                    blackStart = !blackStart;
                }
            }
            cout << (f % 2 == 0 ? "\u2502" : "\u258C") << " " << ID::toFile(f) << endl;
        }
        cout << "  " << INFO::fileBorders[8] << endl;
        print_ranks_line();
        cout << endl;
    }

    void print_ranks_line()
    {
        cout << "  ";
        for (int r = 0; r < 8; r++)
        {
            cout << "  " << ID::toRank(r) << " ";
        }
        cout << endl;
    }

    void play()
    {
        while (true)
        {
            // Display previous moves
            displayPreviousMoves();
            cout << "here" << endl;

            // Display board
            displayBoard();
            cout << "here, maybe" << endl;

            // Display move input area & get next move
            displayMoveInputArea();

            // Do something with the move
            // Find the piece
            // Check if the move is valid
            // Move the piece
            cout << "Data point a" << endl;
            int rawr;
            cin >> rawr;

            int idf = ID::fromFile(move.file);
            int idr = ID::fromRank(move.rank);
            Piece activepiece;
            bool foundPiece = false;
            for (Piece piece : this->pieces[this->isWhitesTurn ? 0 : 1])
            {
                // Check if piece is the right type
                if (piece.type != move.pieceType)
                {
                    continue;
                }
                // Check if piece has idf, idr in valid moves
                for (auto validMove : piece.validMoves)
                {
                    if (validMove[0] == idf && validMove[1] == idr)
                    {
                        cout << "Found piece " << piece.type << " at " << ID::coordsToFR(idf, idr) << endl;
                        activepiece = piece;
                        foundPiece = true;
                        break;
                    }
                }
                if (foundPiece)
                {
                    break;
                }
            }

            cout << "Data point b" << endl;
            cin >> rawr;

            // delete old piece
            // move active piece
            // replace with empty piece
            // this->grid[idf][idr].removePiece();
            cout << "Data point b.5" << endl;
            cin >> rawr;
            this->grid[idf][idr].addPiece(activepiece);
            cout << "Data point c" << endl;
            cin >> rawr;

            this->grid[activepiece.f][activepiece.r].removePiece();
            // Piece emptyPiece;
            // this->grid[activepiece.f][activepiece.r].addPiece(emptyPiece);
            activepiece.moveTo(idf, idr);
            cout << "Data point d" << endl;

            // Update moves lists & other info
            updateMoveList();

            // Switch turns
            this->isWhitesTurn = !this->isWhitesTurn;

            if (this->turnNumber > 1)
            {
                // Check for checkmate
            }

            if (this->turnNumber > 5)
            {
                break;
            }
        }

        cout << endl;
    }

    void displayPreviousMoves()
    {
        if (this->turnNumber == 1)
        {
            return;
        }
        cout << endl
             << endl
             << "Turn history:" << endl;
        for (int i = 0; i < this->turnNumber - 1; i++)
        {
            cout << i + 1 << " \u2502 " << this->moves[0][i] << " \u2502 " << this->moves[1][i] << endl;
        }
    }

    void displayMoveInputArea()
    {
        cout << (this->isWhitesTurn ? "White" : "Black") << "'s turn!" << endl;
        cout << this->turnNumber << " \u2502 w: " << (this->isWhitesTurn ? "" : (this->lastWhiteMove + " \u2502 b: "));

        unpackMove();

        cout << endl;
        for (int i = 0; i < 38; i++)
        {
            cout << "\u2501";
        }
        cout << endl;
        cout << "made it here" << endl;
    }

    void unpackMove()
    {
        string input;
        cin >> input;
        int s = input.size();

        for (int i = 0; i < s; i++)
        {
            input[i] = tolower(input[i]);
        }

        if (s < 2)
        {
            return;
        }

        // Possible inputs:
        // e4
        // xe4
        // Be4
        // O-O
        // Bxe4
        // Bce4
        // B2e4
        // Bcxe4
        // B2xe4
        // Bc2e4
        // O-O-O
        // Bc2xe4
        // Any of these, but with '+' or '#'

        // char piece, idingfile, idingrank, takes, file, rank, special;
        int x = input.find('x');
        move.takes = (x != string::npos ? 'x' : '\0');

        // Castling:
        // if (input[0] == 'o')
        // {
        //     move[6] = (s < 5 ? 'k' : 'q');
        //     return;
        // }
        // else if (this->isCapturing)
        // {
        // }

        move.pieceType = s == 2 ? 'p' : tolower(input[0]);
        move.file = tolower(input[s - 2]);
        move.rank = input[s - 1];
        move.idingfile = s == 4 ? tolower(input[1]) : '\0';
    }

    void updateMoveList()
    {
        string moveAsString = string({move.pieceType, move.idingfile, move.idingrank, move.takes, move.file, move.rank, move.check});
        if (this->isWhitesTurn)
        {
            this->lastWhiteMove = moveAsString;
        }
        else
        {
            this->moves[0].push_back(this->lastWhiteMove);
            this->moves[1].push_back(moveAsString);
            this->turnNumber++;
        }
    }
};
