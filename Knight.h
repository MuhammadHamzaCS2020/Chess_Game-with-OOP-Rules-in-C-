#ifndef KNIGHT_H
#define KNIGHT_H
#include "ChessPiece.h"
#include <iostream>
class Knight:public ChessPiece{
    private:
       char signe;
    public:
        Knight();
        Knight(int,int,color);
       virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8]);
       virtual void setsigne();
       virtual char getsigne();
       virtual void SetData(int,int,color);
        virtual ~Knight();

};

#endif // KNIGHT_H
