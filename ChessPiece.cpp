#include "ChessPiece.h"
ChessPiece::ChessPiece()
{

}
void ChessPiece::Setrow(int x){
    this->row=x;
}
void ChessPiece::Setcol(int y){
    this->col=y;
}
int ChessPiece::getrow(){
    return this->row;
}
int ChessPiece::getcol(){
    return this->col;
}
void ChessPiece::setcolor(color col){
    this->Indication=col;
}
color ChessPiece::getcolor(){
     return this->Indication;
}

ChessPiece::~ChessPiece()
{
    //dtor
}
