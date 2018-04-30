#ifndef QUEEN_H
#define QUEEN_H
#include "ChessPiece.h"
class Queen:public ChessPiece{
    private:
       char signe;
    public:
        Queen();
        Queen(int,int,color);
        virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8]);
        virtual void setsigne();
        virtual char getsigne();
        virtual void SetData(int,int,color);
        virtual ~Queen();

};

#endif // QUEEN_H
