#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include "ChessBoard.h"
#include <string>
using namespace std;
enum color{Black=1,White,Hamza};
class ChessBoard;
class ChessPiece{

    protected:
        int row,col;
        color Indication;
    private:
    public:

        ChessPiece();
        void Setrow(int x);
        void Setcol(int y);
        int getrow();
        int getcol();
        void setcolor(color);
        color getcolor();
        virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8])=0;
        virtual void setsigne()=0;
        virtual char getsigne()=0;
        void SetData(int x,int y,color col);
         ~ChessPiece();

};

#endif // CHESSPIECE_H
