#include "Knight.h"
#include "Blank.h"
#include <iostream>
Knight::Knight()
{
    //ctor
}
Knight::Knight(int x,int y, color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}

bool ConditionCheck(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
    if(sr==sc && er==ec){
        return false;
    }
    else
        if(obj[sr][sc]->getcolor()==obj[er][ec]->getcolor()){
        return false;
    }
    else
        if ((sr+2==er && sc+1==ec) || (sr+2==er && sc-1==ec) || (sc+2==ec && sr+1) || (sc+1==ec && sr+2==er) || (sr-1==er && sc-2==ec)){
        return true;

    }
    else
        if ((sc+2==ec && sr-1==er) || (sr+1==er && sc-2==ec) || (sc-1==ec && sr-2==er) || (sr-2==er && sc+1==ec)){
        return true;
    }
    else
        return false;
}

bool Knight::LegalMoves(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
     bool flage1=true;
     flage1=ConditionCheck(sr,sc,er,ec,obj);
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
        cout<<"Wrong Input\n";
        return false;
       }

}
void Knight::setsigne(){
   if(this->Indication==Black)
      this->signe='n';
   else if(this->Indication==White)
      this->signe='N';
   else
      this->signe='\0';
}
void Knight::SetData(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}

char Knight::getsigne(){
  return this->signe;
}

Knight::~Knight()
{
    //dtor
}
