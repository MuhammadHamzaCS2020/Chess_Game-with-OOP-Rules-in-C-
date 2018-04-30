#include "Queen.h"
#include "Blank.h"
#include <iostream>
Queen::Queen()
{

}

Queen::Queen(int x,int y, color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}
bool QueenConditionCheck(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
        bool flage=true;
        int flage1,flage2;

    if(obj[sr][sc]->getcolor()==obj[er][ec]->getcolor()){
      return false;
    }
    /// Rook Like Moves...
    else if(sc==ec){
         if(sr>er){
           for(int i=er+1; i<sr; i++){
             if(obj[i][sc]->getcolor()!=Hamza)
               return false;
           }
         }
         else{
            for(int i=sr+1; i<er; i++){
             if(obj[i][sc]->getcolor()!=Hamza)
               return false;
            }
         }
    }
    else if(sr==er){
         if(sc>ec){
           for(int i=ec+1; i<sc; i++){
             if(obj[sr][i]->getcolor()!=Hamza)
               return false;
           }
         }
         else{
            for(int i=sc+1; i<ec; i++){
             if(obj[sr][i]->getcolor()!=Hamza)
               return false;
            }
         }
    }
/// Like Bishop Moves
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
    else
        cout<<"\nWrong Input...\n";
    return true;
}
bool Queen::LegalMoves(int sr,int sc,int er,int ec,ChessPiece *obj[8][8]){
     bool flage1=true;
     flage1=QueenConditionCheck(sr,sc,er,ec,obj);
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

void Queen::setsigne(){
   if(this->Indication==Black)
      this->signe='q';
   else if(this->Indication==White)
      this->signe='Q';
   else
      this->signe='\0';
}
void Queen::SetData(int x,int y,color col){
    this->row=x;
    this->col=y;
    this->Indication=col;
}
char Queen::getsigne(){
  return this->signe;
}
Queen::~Queen()
{
    //dtor
}
