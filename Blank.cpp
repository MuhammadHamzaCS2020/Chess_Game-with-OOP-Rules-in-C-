#include "Blank.h"

Blank::Blank()
{
    //ctor
}


Blank::Blank(int x,int y, color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
    this->signe='-';
    //getsigne();
}
bool Blank::LegalMoves(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){

}
void Blank::setsigne(){
   if(this->Indication==Black)
      this->signe='-';
   else if(this->Indication==White)
      this->signe='-';
   else
      this->signe='-';
}
void Blank::SetData(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}
char Blank::getsigne(){
  return this->signe;
}

Blank::~Blank()
{
    //dtor
}
