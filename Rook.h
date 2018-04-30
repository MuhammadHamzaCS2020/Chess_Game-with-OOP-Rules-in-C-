#ifndef ROOK_H
#define ROOK_H
#include "ChessPiece.h"

class Rook:public ChessPiece{
    private:
        char signe;
    public:
        Rook();
        Rook(int,int,color);
        void SetData(int, int, color);
        virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8]);
        virtual void setsigne();
        virtual char getsigne();
        virtual ~Rook();
};

#endif // ROOK_H
