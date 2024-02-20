
#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';

int row, col;

bool draw = false;

void displayBoard();
void playerTurn();
bool gameOver();


int main()
{
    while( gameOver()){
    displayBoard();
    playerTurn();
    }

    if(turn == 'X' && draw == false){
        cout<<"Player2 [O] Wins!! Congrats";
    }
    else if(turn == 'O' && draw == false){
        cout<<"Plalyer1 [X] Wins !! congrats;;";
    }
    else{
        cout<<"Game Draw!!";
    }

    return 0;
}
void displayBoard()
{
    system("cls");
    cout << "\n\t\t  Tic Tac Toe Game" << endl;
    cout << "\t\t\tPlayer1 [X]" << endl;
    cout << "\t\t\tPlayer2 [O]" << endl
         << endl;
    cout << "\t\t\t        |        |        " << endl;
    cout << "\t\t\t    " << board[0][0] << "   |    " << board[0][1] << "   |   " << board[0][2] << "    " << endl;
    cout << "\t\t\t________|________|________" << endl;
    cout << "\t\t\t        |        |        " << endl;
    cout << "\t\t\t    " << board[1][0] << "   |    " << board[1][1] << "   |   " << board[1][2] << "    " << endl;
    cout << "\t\t\t________|________|________" << endl;
    cout << "\t\t\t        |        |        " << endl;
    cout << "\t\t\t    " << board[2][0] << "   |    " << board[2][1] << "   |   " << board[2][2] << "    " << endl;
    cout << "\t\t\t        |        |        " << endl;
}

void playerTurn()
{
    int choice;
    if (turn == 'X')
    {
        cout << "\n\t\tPlayer1 [X] Turn:";
    }
    if (turn == 'O')
    {
        cout << "\n\t\tPlayer2 [O] Turn:";
    }
    cin >> choice;
    switch (choice)
    {
    case 1:
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;
    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;
    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;

    default:
        cout<<"Invalid choice \n";
        break;
    }
    if(turn == 'X' && board[row][col]!= 'X' && board[row][col]!= 'O'){
        board[row][col] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && board[row][col]!= 'X' && board[row][col]!= 'O'){
        board[row][col] = 'O';
        turn = 'X';
    }
    else{
        cout<<"Box Already filled please try Again\n";
        playerTurn();
    }
    displayBoard();
}

bool gameOver(){
    // Check Win
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return false;
        }
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]){
            return false;
        }
    }

    // If there any box not filled
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return true;
            }
        }
    }

    // draw
    draw = true;
    return false;
};