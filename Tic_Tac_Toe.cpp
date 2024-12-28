#include <bits/stdc++.h>
using namespace std;
char box[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player = 'X';

void display(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<box[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check(){
    for(int i=0;i<3;i++){
        if(box[i][0]==box[i][1] && box[i][1]==box[i][2]) return true;
        if(box[0][i]==box[1][i] && box[1][i]==box[2][i]) return true;
    }
    if(box[0][0]==box[1][1] && box[1][1]==box[2][2]) return true;
    if(box[0][2]==box[1][1] && box[1][1]==box[2][0]) return true;
    return false;
}

void play(){
    int move;
    cout<<"Player "<<player<<"; Enter Position: ";
    cin>>move;
    if(move>9){
        cout<<"Invalid Move.. Try Again.!"<<endl;
        play();
    }
    int row = (move-1)/3;
    int column = (move-1)%3;
    if(box[row][column]!='O' && box[row][column]!='X'){
        box[row][column] = player;
        if(player=='X'){
            player = 'O';
        }
        else{
            player = 'X';
        }
    }
    else{
        cout<<"Invalid Move.. Try Again.!"<<endl;
        play();
    }
}
int main() {
    int move = 0;
    display();
    while(move<9){
        play();
        display();
        if(check()){
            if(player=='X'){
                cout<<"Player 'O' Wins!"<<endl;
                return 0;
            }
            else{
                cout<<"Player 'X' Wins!"<<endl;
                return 0;
            }
        }
        move++;
    }
    cout<<"Match Draw!"<<endl;
    return 0;
}