#ifndef BISHOP_H
#define BISHOP_H
#include "ChessPiece.h"
class Bishop:public ChessPiece{
    private:
       char signe;
    public:
        Bishop();
        Bishop(int,int,color);
        virtual bool LegalMoves(int,int,int,int,ChessPiece *obj[8][8]);
        virtual void setsigne();
        virtual char getsigne();
        virtual void SetData(int,int,color);
        virtual ~Bishop();

};

#endif // BISHOP_H
