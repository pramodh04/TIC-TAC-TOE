#include <iostream>

using namespace std;

char Board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char curr_marker;
int curr_player;




bool placeMarker(int slot)
{
    int row=slot/3,col=0;
    if(slot%3==0)
    {
        row=row-1;
        col=2;
    }
    else
        col=(slot%3) - 1;
        if(Board[row][col] != 'X' && Board[row][col] != 'O')
        {
         Board[row][col]=curr_marker;
         return true;
        }
        else return false;

}



void drawBoard()
{
    cout<<Board[0][0]<<'|'<<Board[0][1]<<'|'<<Board[0][2]<<endl;
    cout<<"------"<<endl;
    cout<<Board[1][0]<<'|'<<Board[1][1]<<'|'<<Board[1][2]<<endl;
    cout<<"------"<<endl;
    cout<<Board[2][0]<<'|'<<Board[2][1]<<'|'<<Board[2][2]<<endl;

}

int winner()
{
    for(int i=0;i<3;i++)
    {
        if(Board[i][0]==Board[i][1] && Board[i][1]==Board[i][2])
            return curr_player;
        if(Board[0][i]==Board[1][i] && Board[1][i]==Board[2][i])
            return curr_player;
    }

        if(Board[0][0]==Board[1][1] && Board[1][1]==Board[2][2])
            return curr_player;
        if(Board[2][0]==Board[1][1] && Board[1][1]==Board[0][2])
            return curr_player;

            return 0;
}
void swap_Player_Marker()
{
    if(curr_marker=='X') curr_marker='O';
    else curr_marker='X';

    if(curr_player==1) curr_player=2;
    else curr_player=1;
}

void game()
{
    cout<<"Player one, Choose your marker:";
    char marker_p1;
    cin>>marker_p1;

    curr_player= 1;

    curr_marker = marker_p1;
    int player_won;
    for(int i=0;i<9;i++)
    {
        cout<<"It's player "<<curr_player<<"'s turn.select your slot"<<endl;
        int slot;
        cin >> slot;
        if(slot<1 || slot>9)
        {
            cout<<"Slot is invalid, enter a new slot"<<endl;
            i--;
            continue;
        }

        if(!placeMarker(slot))
        {
            cout<<"Slot is already occupied, enter a new slot"<<endl;
            i--;
            continue;
        }

        drawBoard();
        player_won = winner();
        if(player_won == 1) {cout<<"Player one won. Congratulations!"<<endl; break; }
        if(player_won == 2) {cout<<"Player two won. Congratulations!"<<endl; break; }

        swap_Player_Marker();

    }
    if(player_won==0) cout<<"That's a tie. Try a new game"<<endl;
}



int main()
{
   game();
   return 0;
}


