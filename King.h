#ifndef KING_H
#define KING_H
#include "ChessPiece.h"
class King:public ChessPiece{
    private:
        char signe;
    public:
        King();
        King(int,int,color);
        virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8]);
        virtual void setsigne();
        virtual char getsigne();
        virtual void SetData(int,int,color);
        virtual ~King();
};

#endif // KING_H
