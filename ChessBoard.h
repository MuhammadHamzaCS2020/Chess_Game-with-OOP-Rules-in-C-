#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <array>
#include "ChessPiece.h"
using namespace std;
const int ROWSIZE=8;
const int COLSIZE=8;
class ChessPiece;
class ChessBoard{
    private:
         ChessPiece* board[ROWSIZE][COLSIZE];
    public:
        ChessBoard();
        void DisplayBoard();
        void Initializ();
        void Gamearena();
        virtual ~ChessBoard();


};

#endif // CHESSBOARD_H
