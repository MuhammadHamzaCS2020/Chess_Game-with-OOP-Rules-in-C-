#include "ChessBoard.h"
#include<iostream>
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Blank.h"
using namespace std;
int getstartrow(string str);
int getstartcol(string str);
int getendrow(string str);
int getendcol(string str);


ChessBoard::ChessBoard(){
   for(int i=0; i<ROWSIZE; i++)
     for(int j=0; j<COLSIZE; j++)
          board[i][j]='\0';

}
void ChessBoard::Initializ(){

    Pawn pawnobj[8],pawnobj1[8];
    Rook rookobj[2],rookobj1[2];
    Knight kobj[2],kobj1[2];
    Bishop bobj[2],bobj1[2];
    Queen qobj[2];
    King Kobj1[2];


    for (int i=0; i<ROWSIZE; i++){
        pawnobj[i].SetData(6,i,Black);
        pawnobj[i].setsigne();
        board[6][i]=&pawnobj[i];
    }
    for (int i=0; i<ROWSIZE; i++){
        pawnobj1[i].SetData(1,i,White);
        pawnobj1[i].setsigne();
        board[1][i]=&pawnobj1[i];
    }
    /// rook initialization on the board...
    rookobj[0].SetData(7,0,Black);
    board[7][0]=&rookobj[0];
    rookobj[1].SetData(7,7,Black);
    board[7][7]=&rookobj[1];

    rookobj1[0].SetData(0,0,White);
    board[0][0]=&rookobj1[0];
    rookobj1[1].SetData(0,7,White);
    board[0][7]=&rookobj1[1];

/// Knight Initialization
    kobj[0].SetData(7,1,Black);
    kobj[0].setsigne();
    board[7][1]=&kobj[0];

    kobj[1].SetData(7,6,Black);
    kobj[1].setsigne();
    board[7][6]=&kobj[1];

    kobj1[0].SetData(0,1,White);
    kobj1[0].setsigne();
    board[0][1]=&kobj1[0];

    kobj1[1].SetData(0,6,White);
    kobj1[1].setsigne();
    board[0][6]=&kobj1[1];

/// bishop Initialization

    bobj[0].SetData(7,5,Black);
    bobj[0].setsigne();
    board[7][5]=&bobj[0];

    bobj[1].SetData(7,2,Black);
    bobj[1].setsigne();
    board[7][2]=&bobj[1];

    bobj1[0].SetData(0,2,White);
    bobj1[0].setsigne();
    board[0][2]=&bobj1[0];

    bobj1[1].SetData(0,5,White);
    bobj1[1].setsigne();
    board[0][5]=&bobj1[1];

/// queen and king Initialization

    qobj[0].SetData(7,3,Black);
    qobj[0].setsigne();
    board[7][3]=&qobj[0];

    qobj[1].SetData(0,3,White);
    qobj[1].setsigne();
    board[0][3]=&qobj[1];

    Kobj1[0].SetData(7,4,Black);
    Kobj1[0].setsigne();
    board[7][4]=&Kobj1[0];

    Kobj1[1].SetData(0,4,White);
    Kobj1[1].setsigne();
    board[0][4]=&Kobj1[1];

    Blank blanck[32];
    int counter=0;
   for(int i=2; i<=5; i++){
     for(int j=0; j<COLSIZE; j++){
           blanck[counter].SetData(i,j,Hamza);
           blanck[counter].setsigne();
           board[i][j]=&blanck[counter];
           counter++;
     }
     std::cout<<std::endl;
   }
   DisplayBoard();
   Gamearena();
}


int GetIntFromString(char *temp,int index){
     int chach;
     if(temp[index]>=48 && temp[index]<=57){
         chach=temp[index]-48;
         return chach;
     }
     else
     if(temp[index]>=97 && temp[index]<=122){
        chach=temp[index]-97;
        return chach;
     }
     else
     if(temp[index]>=65 && temp[index<=90]){
        chach=temp[index]-65;
        return chach;
     }
     else
        cout<<"Wrong Input\n";
}

/// Game Arena
void ChessBoard::Gamearena(){
    const int SIZE=10;
    int terms=0,Player1Terms=0,Player2Terms=0;
    char str[SIZE],Player1[20],Player2[20];
    cout<<"Player one Name: ";
    cin.getline(Player1,20);
    cout<<"Player Two Name: ";
    cin.getline(Player2,20);
     int sc,sr,ec,er;
     bool flage;
    ///   Forever Loop...
 while(true){
        cout<<Player1<<" Terms :"<<Player1Terms<<endl
        <<Player2<<" Terms :"<<Player2Terms<<endl
        <<"Total Correct Moves :"<<terms<<endl;
        DisplayBoard();
        if(terms%2==0){
                Player1Terms++;
            cout<<"Black Player "<<Player1<<" :";
            cin.getline(str,SIZE);
              sc=GetIntFromString(str,0);  /// Starting Column
              sr=GetIntFromString(str,1);  /// Starting row
              er=GetIntFromString(str,7);  /// End row
              ec=GetIntFromString(str,6);  /// Ending Col

                 if(board[sr][sc]->getcolor()!=Black){
                    cout<<"\nWrong Input \n";
                    continue;
                 }
               flage=board[sr][sc]->LegalMoves(sr,sc,er,ec,board);
                if(flage==false)
                    continue;

        }
        else
           if(terms%2==1){
                Player2Terms++;
             cout<<" White Player "<<Player2<<" :";
             cin.getline(str,SIZE);
              sc=GetIntFromString(str,0);  /// Starting Column
              sr=GetIntFromString(str,1);  /// Starting row
              er=GetIntFromString(str,7);  /// End row
              ec=GetIntFromString(str,6);  /// Ending Col
                 if(board[sr][sc]->getcolor()!=White){
                    cout<<"\nWrong Input \n";
                    continue;
                  }
                flage=board[sr][sc]->LegalMoves(sr,sc,er,ec,board);
                  if(flage==false)
                    continue;
           }
           flage=true;
          terms++;
   }
}

void ChessBoard::DisplayBoard(){
   cout<<"\n\t'Black'\n";
   cout<<endl<<"    ";
   for(char i='a'; i<='h'; i++){
      cout<<i<<" ";
   }std::cout<<std::endl<<endl;
   for(int i=ROWSIZE-1; i>=0; i--){
        cout<<i<<"   ";
     for(int j=0; j<COLSIZE; j++){
        cout<<board[i][j]->getsigne()<<" ";
     }
     cout<<endl;
   }
   cout<<endl<<"\t'White'\n\n";
}

ChessBoard::~ChessBoard()
{

}
