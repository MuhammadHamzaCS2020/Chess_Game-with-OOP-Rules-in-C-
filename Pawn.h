#ifndef PAWN_H
#define PAWN_H
#include "ChessPiece.h"
class Pawn:public ChessPiece{
    private:
       char signe;
       bool One_Two;
    public:
        Pawn();
        Pawn(int x,int y,color col);
        bool Get_One_two_Check();
        virtual void SetData(int, int, color);
        virtual void setsigne();
        virtual char getsigne();
        virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8]);
        virtual ~Pawn();

};

#endif // PAWN_H
