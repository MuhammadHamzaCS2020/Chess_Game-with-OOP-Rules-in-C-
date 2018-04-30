#ifndef BLANK_H
#define BLANK_H
#include "ChessPiece.h"

class Blank:public ChessPiece{
    public:
        Blank();
        Blank(int,int,color);
        virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8]);
        virtual void setsigne();
        virtual char getsigne();
        virtual void SetData(int,int,color);
        virtual ~Blank();
    protected:
    private:
        char signe;
};

#endif // BLANK_H

