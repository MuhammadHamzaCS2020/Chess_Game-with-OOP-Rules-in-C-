#include "Pawn.h"
#include "Blank.h"
#include <iostream>
#include <cstdlib>
Pawn::Pawn(){

}
Pawn::Pawn(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
    this->One_Two=true;
}
void Pawn::SetData(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}
bool Pawn::Get_One_two_Check(){
    return One_Two;
}

bool Pawnconditions(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){

   int clr;
   clr=obj[sr][sc]->getcolor();
   if(clr==White){
        if(er==sr-1&& ec==sc){
           return false;
         }
       else if((er==sr+1)&&(sc==ec)){
           if(obj[er][ec]->getcolor()==Hamza){
               return true;
           }
           else{
               return false;
           }
       }
       else if((er==sr+1)&&((ec==sc+1)||(ec==sc-1))){
           if(obj[er][ec]->getcolor()==Black){
               return true;
           }
           else{
               return false;
           }
       }
   }
   else if(clr==Black){
       if(er==sr+1){
           return false;
       }
       else if((er==sr-1)&&(sc==ec)){
           if(obj[er][ec]->getcolor()==Hamza){
               return true;
           }
           else{
               return false;
           }
       }
       else if((er==sr-1)&&((ec==sc+1)||(ec==sc-1))){
           if(obj[er][ec]->getcolor()==White){
               return true;
           }
        else{
               return false;
           }
       }
   }
   return false;
}

bool Pawn::LegalMoves(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
 bool flage1=true;
     flage1=Pawnconditions(sr,sc,er,ec,obj);
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

void Pawn::setsigne(){
   if(this->Indication==Black)
      this->signe='p';
   else if(this->Indication==White)
      this->signe='P';
   else
      this->signe='_';
}
char Pawn::getsigne(){
  return this->signe;
}
Pawn::~Pawn()
{
    //dtor
}
