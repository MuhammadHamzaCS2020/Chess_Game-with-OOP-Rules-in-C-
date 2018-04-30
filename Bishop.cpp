#include "Bishop.h"
#include "Blank.h"
#include<iostream>
#include <stdlib.h>
using namespace std;
Bishop::Bishop()
{
}
Bishop::Bishop(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}


int BishopConditioon(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){

    int flage1,flage2;

       if(obj[sr][sc]->getcolor()==obj[er][ec]->getcolor()){
            return false;
        }
        else
           if(sr==er || sc==ec){
           return false;
         }
        else
            if((sr<er)&&(sc<ec)){
                    flage1=er-sr;
                    flage2=ec-sc;
              if(flage1!=flage2){
                  return false;
              }
               else{
                  for(int i=1;(i+sr)<er;i++){
                    if((obj[sr+i][sc+i]->getcolor()!=Hamza))
                      return false;
                   }
                }
            }
        else
            if((sr>er)&&(sc>ec)){
                    flage1=sr-er;
                    flage2=sc-ec;
              if(flage1!=flage2){
                return false;
              }
              else{
                 for(int i=1;(sr-i)>er;i++){
                    if((obj[sr-i][sc-i]->getcolor()!=Hamza) )
                    return false;
                 }
              }
           }
        else
           if((sr>er)&&(sc<ec)){
                    flage1=sr-er;
                    flage2=ec-sc;
                    if(flage1!=flage2){
                        return false;
                    }
                    else{
                      for(int i=1;(sr-i)>er;i++){
                        if((obj[sr-i][er+i ]->getcolor()!=Hamza ))
                           return false;
                 }
              }
          }
       else
           if((sr<er)&&(sc>ec)){
                    flage1=er-sr;
                    flage2=sc-ec;
                    if(flage1!=flage2){
                        return false;
                    }
              else{
                for(int i=1;(sc-i)>ec;i++){
                   if((obj[sr+i][sc-i]->getcolor()!=Hamza))
                   return false;
                   }
             }
          }
    return true;
    }

bool Bishop::LegalMoves(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
     bool flage1=true;
     flage1=BishopConditioon(sr,sc,er,ec,obj);
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
void Bishop::setsigne(){
   if(this->Indication==Black)
      this->signe='b';
   else if(this->Indication==White)
      this->signe='B';
   else
      this->signe='\0';
}
void Bishop::SetData(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;

}
char Bishop::getsigne(){
  return this->signe;
}
Bishop::~Bishop()
{
    //dtor
}
