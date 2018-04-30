#include "Rook.h"
#include "Blank.h"
#include <iostream>
static int counter=0;
Rook::Rook()
{

}
Rook::Rook(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
    setsigne();
}
bool RookCondition(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
    int counter=0;
    if(obj[sr][sc]->getcolor()==obj[er][ec]->getcolor()){
       counter=1;//return false;
    }
    else if(sc==ec){
         if(sr>er){
           for(int i=er+1; i<sr; i++){
             if(obj[i][sc]->getcolor()!=Hamza)
               counter=1;//return false;
           }
         }
         else{
            for(int i=sr+1; i<er; i++){
             if(obj[i][sc]->getcolor()!=Hamza)
              counter=1;//return false;
            }
         }
    }
     else if(sr==er){
         if(sc>ec){
           for(int i=ec+1; i<sc; i++){
             if(obj[sr][i]->getcolor()!=Hamza)
              counter=1;//return false;
           }
         }
         else{
            for(int i=sc+1; i<ec; i++){
             if(obj[sr][i]->getcolor()!=Hamza)
              counter=1;//return false;
            }
         }
    }
    else{
       cout<<"\nWrong Input...\n";
      return false;
    }
     if(counter==0)
        return true;
     if(counter==1)
        return false;

}
bool Rook::LegalMoves(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
     bool flage=true;
     flage=RookCondition(sr,sc,er,ec,obj);
      if(flage==true){
         obj[er][ec]=obj[sr][sc];
         obj[er][ec]->Setrow(er);
         obj[er][ec]->Setcol(ec);
         obj[sr][sc]=new Blank(sr,sc,Hamza);
         obj[sr][sc]->Setrow(sr);
         obj[sr][sc]->Setcol(sc);
         return true;
      }
      else{
         std::cout<<"\nThis wrong Input...";
         return false;
      }

}
void Rook::SetData(int x,int y,color c){
    this->row=x;
    this->col=y;
    this->Indication=c;
    setsigne();
}
void Rook::setsigne(){
  if(this->Indication==Black)
      this->signe='r';
   else if(this->Indication==White)
     this->signe='R';
   else
      this->signe='-';
}
char Rook::getsigne( ){
  return this->signe;
}
Rook::~Rook()
{
    //dtor
}
