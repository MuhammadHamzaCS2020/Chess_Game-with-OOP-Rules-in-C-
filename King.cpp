#include "King.h"
#include "Blank.h"
#include <iostream>
#include <stdlib.h>
King::King()
{
    ///ctor
}
King::King(int x,int y, color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}
bool Kingcondition(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
   if(obj[sr][sc]->getcolor()==obj[er][ec]->getcolor()){
       return false;
    }
   else
      if(sr==er){
         if((sc-ec==1) || sc-ec==-1){
           return true;
         }
         else{
           return false;
         }
      }
   else
      if(sc==ec){
         if((sr-er==1) || sr-er==-1){
           return true;
         }
         else {
           return false;
         }
      }
    else
      if(abs(sr-er)==1 && abs(sc-ec)==1){
          return true;
      }
   else {
      return false;
    }
}
bool King::LegalMoves(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
 bool flage1=true;
     flage1=Kingcondition(sr,sc,er,ec,obj);
      if(flage1==true){
         obj[er][ec]=obj[sr][sc];
         obj[er][ec]->Setrow(er);
         obj[er][ec]->Setcol(ec);
         obj[sr][sc]=new Blank(sr,sc,Hamza);
         obj[sr][sc]->Setrow(sr);
         obj[sr][sc]->Setcol(sc);
         return true;
      }
     else{
        std::cout<<"Wrong Input\n";
        return false;
      }
}
void King::setsigne(){
   if(this->Indication==Black)
      this->signe='k';
   else if(this->Indication==White)
      this->signe='K';
   else
      this->signe='\0';
}
void King::SetData(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}
char King::getsigne(){
  return this->signe;
}
King::~King()
{
    //dtor
}
