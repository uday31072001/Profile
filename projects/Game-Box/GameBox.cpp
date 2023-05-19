#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void showAbout();
void play();
void printGameBox();

int main() {
    system("cls");
    char op;
    while(1){
        printGameBox();
        cout<<"\nMENU\n"<<endl;
        cout<<"> 1. Play"<<endl;
        cout<<"> 2. About"<<endl;
        cout<<"> 3. Exit"<<endl;
        cout<<"\nEnter : ";    
        cin>>op;
        while(!isdigit(op)){
            cout<<"Enter a valid option\nEnter : ";
            cin>>op;
        }
        switch(op){
            case '1':
                system("cls");
                play();
                break;
            case '2':
                system("cls");
                showAbout();
                break;
            case '3':
                exit(0);
                break;
            default:
                system("cls");
                continue;
        }
    }
   return 0;
}

class TicTacToe{
    private:
        void playvc(){
            int pos=0,_c=9;
            char board[3][3];
            blankboard(board);
            cout<<"\n||\tGame Begins\t||\n"<<endl;
            for(int i=0;i<10;i++){
                system("cls");
                int s=check(board,_c);
                switch(s){
                    case 1:
                        display_board(board);
                        cout<<"----------------------\n"<<endl;
                        cout<<"||   Player 1 Wins   ||\n"<<endl;
                        cout<<"----------------------\n"<<endl;
                        return;
                    case 2:
                        display_board(board);        
                        cout<<"----------------------\n"<<endl;
                        cout<<"||  Computer Wins   ||\n"<<endl;
                        cout<<"----------------------\n"<<endl;
                        return;
                    case 3:
                        display_board(board);
                        cout<<"----------------------\n"<<endl;
                        cout<<"||       Draw       ||\n"<<endl;
                        cout<<"----------------------\n"<<endl;
                        return;
                }
                display_board(board);
                if(i%2==0){
                    //player 1
                    cout<<"\nPlayer 1 Enter postion : ";
                    cin>>pos;
                    if(!update(board,pos,'X',0))
                        i--;
                    else{   
                        _c--;
                    }
                }
                else{
                    //comp
                    cout<<"\nComputer Turn"<<endl;
                    srand((unsigned) time(0));
                    pos = (rand() % 9) + 1;
                    while(!update(board,pos,'O',1))
                        {
                            srand((unsigned) time(0));
                            pos = (rand() % 9) + 1;
                        }   
                        _c--;
                }
            }
        }

        void playpp(){
            int pos=0,_c=9;
            char board[3][3];
            blankboard(board);
            cout<<"\n||\tGame Begins\t||\n"<<endl;
            for(int i=0;i<10;i++){
                system("cls");
                int s=check(board,_c);
                switch(s){
                    case 1:
                        display_board(board);
                        cout<<"----------------------\n"<<endl;
                        cout<<"||   Player 1 Wins   ||\n"<<endl;
                        cout<<"----------------------\n"<<endl;
                        return;
                    case 2:
                        display_board(board);       
                        cout<<"----------------------\n"<<endl;
                        cout<<"||   Player 2 Wins   ||\n"<<endl;
                        cout<<"----------------------\n"<<endl;
                        return;
                    case 3:
                        display_board(board);
                        cout<<"----------------------\n"<<endl;
                        cout<<"||       Draw       ||\n"<<endl;
                        cout<<"----------------------\n"<<endl;
                        return;
                }
                display_board(board);
                if(i%2==0){
                    //player 1
                    cout<<"\nPlayer 1 Enter postion : ";
                    cin>>pos;
                    if(!update(board,pos,'X',0))
                        i--;
                    else{   
                        _c--;
                    }
                }
                else{
                    //player 2
                    cout<<"\nPlayer 2 Enter postion"<<endl;
                    cin>>pos;
                    if(!update(board,pos,'O',0))
                        i--;
                    else   
                        _c--;
                }
            }
        }

        int check(char b[3][3],int blank){
            if
            ( 
                //player 1 wins
                (b[0][0]=='X'&&b[0][1]=='X'&&b[0][2]=='X') || (b[1][0]=='X'&&b[1][1]=='X'&&b[1][2]=='X') || (b[2][0]=='X'&&b[2][1]=='X'&&b[2][2]=='X') || 
                (b[0][0]=='X'&&b[1][0]=='X'&&b[2][0]=='X') || (b[0][1]=='X'&&b[1][1]=='X'&&b[2][1]=='X') || (b[0][2]=='X'&&b[1][2]=='X'&&b[2][2]=='X') ||
                (b[0][0]=='X'&&b[1][1]=='X'&&b[2][2]=='X') || (b[0][2]=='X'&&b[1][1]=='X'&&b[2][0]=='X')
            )
                return 1;
            else if
            ( 
                //player 2 wins
                (b[0][0]=='O'&&b[0][1]=='O'&&b[0][2]=='O') || (b[1][0]=='O'&&b[1][1]=='O'&&b[1][2]=='O') || (b[2][0]=='O'&&b[2][1]=='O'&&b[2][2]=='O') || 
                (b[0][0]=='O'&&b[1][0]=='O'&&b[2][0]=='O') || (b[0][1]=='O'&&b[1][1]=='O'&&b[2][1]=='O') || (b[0][2]=='O'&&b[1][2]=='O'&&b[2][2]=='O') ||
                (b[0][0]=='O'&&b[1][1]=='O'&&b[2][2]=='O') || (b[0][2]=='O'&&b[1][1]=='O'&&b[2][0]=='O')
            )
                return 2;
            else if(blank==0)
            {
                //draw
                return 3;
            }
            else
                return 0;
        }

        void blankboard(char board[3][3]){
            int k=1;
            cout<<endl<<"BOARD LAYOUT"<<endl;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++,k++){
                    board[i][j]='_';
                    if(j<2)
                        cout<<k<<" | ";
                    else
                        cout<<k<<endl;
                }
                if(i<2)
                    cout<<"----------"<<endl;
            }
        }

        void display_board(char board[3][3]){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(j<2)
                        cout<<board[i][j]<<" | ";
                    else
                        cout<<board[i][j]<<endl;
                }
                if(i<2)
                    cout<<"----------"<<endl;
            }
        }

        int update(char board[3][3],int pos,char a,int c){
            switch(pos){
                case 1:
                    if(board[0][0]=='_')
                    board[0][0]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 2:
                    if(board[0][1]=='_')
                    board[0][1]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 3:
                    if(board[0][2]=='_')
                    board[0][2]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 4:
                    if(board[1][0]=='_')
                    board[1][0]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 5:
                    if(board[1][1]=='_')
                    board[1][1]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 6:
                    if(board[1][2]=='_')
                    board[1][2]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 7:
                    if(board[2][0]=='_')
                    board[2][0]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 8:
                    if(board[2][1]=='_')
                    board[2][1]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                case 9:
                    if(board[2][2]=='_')
                    board[2][2]=a;
                    else if(c)
                        return 0;
                    else
                    {
                        cout<<"position occupied"<<endl;
                        return 0;
                    }
                    break;
                default:
                    cout<<"ERROR: pls choose a postion [1,9] "<<endl;
                    return 0;
                    break;
                return 1;                
            }
        }
    
        void help(){
        system("cls");
        cout<<"HELP\n"<<endl;
        cout<<"Board layout\n\n  1 | 2 | 3\n  ---------\n  4 | 5 | 6\n  ---------\n  7 | 8 | 9\n\n"<<endl;
        cout<<"Rules \n"<<endl; 
        cout<<"> The game is played on a grid that's 3 squares by 3 squares."<<endl;
        cout<<"> You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in empty squares."<<endl;
        cout<<"> The first player to get 3 of her marks in a row up, down, across, or diagonally is the winner."<<endl;
        cout<<"> When all 9 squares are full, the game is over"<<endl;

        cout<<"\nOptions\n"<<endl;
        cout<<"> 1.Return\n"<<endl;
        char op;
        while(1){
            cout<<"Enter : ";
            cin>>op;
            while(!isdigit(op)){
                cout<<"Enter a valid option\nEnter : ";
                cin>>op;
            }
            switch(op){
                case '1':
                    system("cls");
                    return;
                default:
                    cout<<"Enter a valid option\nEnter : ";
                    continue;
                    break;  
            }
        }    
    }


    public: 
        void playTicTacToe(){
            char op;
            int x=1;
            system("cls");
            while(x){
                printGameBox();
                cout<<
                    "\nTIC - TAC - TOE\n\n"
                    "> 1. play with computer\n"
                    "> 2. play with friend\n"
                    "> 3. Help\n"
                    "> 4. Return\n\n"
                    "enter option : ";
                cin>>op;
                while(!isdigit(op)){
                    cout<<"Enter a valid option\nEnter : ";
                    cin>>op;
                }
                switch (op){
                    case '1':
                        playvc();
                        break;
                    case '2':
                        playpp();
                        break;
                    case '3':
                        help();
                        break;
                    case '4':
                        system("cls");
                        return;
                        break;
                    default:
                        system("cls");
                        continue;
                }
            }
        }
        
};

class Othello{
    private:
        int l = 10; //1 space border all sides;
        char board[10][10];
        int coins;
        int li,lj;
        void display_board(){
            HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            cout<<"\n\n";
            for(int i=0;i<l;i++){
                for(int j=0;j<l;j++){
                    if(i==li && j== lj){
                        SetConsoleTextAttribute(h,15);
                        cout<<"#";
                        SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
                    }
                    else if(board[i][j]=='0')
                    {
                        SetConsoleTextAttribute(h,6);//turn text yellow
                        cout<<board[i][j];
                        SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
                    }
                    else if(board[i][j]=='O')
                    {
                        SetConsoleTextAttribute(h,FOREGROUND_GREEN);//turn text green
                        cout<<board[i][j];
                        SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
                    }
                    else if(board[i][j]=='+')
                    {
                        SetConsoleTextAttribute(h,FOREGROUND_RED );//turn text red
                        cout<<board[i][j];
                        SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
                    }
                    else
                        cout<<board[i][j];
                    cout<<" ";
                }
                cout<<endl;    
            }
            SetConsoleTextAttribute(h,15);//white
        }
        void display_menu(){
            printGameBox();
            cout<<"\nOTHELLO\n\n";
            cout<<"> 1. Play\n";
            cout<<"> 2. Help\n";
            cout<<"> 3. Return\n\n";
            cout<<"Enter option : ";
        }
        void help(){
            HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute(h,15);//white
            cout<<"HELP\n"<<endl;
            cout<<"Player coins\n"<<endl;
            cout<<"player 1 = ";
            SetConsoleTextAttribute(h,6 );//turn text yellow
            cout<<"0";
            SetConsoleTextAttribute(h,15);//white
            cout<<" coins"<<endl;
            cout<<"player 2 = ";
            SetConsoleTextAttribute(h,FOREGROUND_GREEN );//turn text red
            cout<<"O";
            SetConsoleTextAttribute(h,15);//turn text white
            cout<<" coins"<<endl;
            cout<<"\nPlayer moves\n\nw : move up\ns : move down\na : move left\nd : move right\n";
            cout<<"x : put coin\nf :decide winner\n"<<endl;
            cout<<"Rules\n"<<endl;
            cout<<
            " The object of this 2 player game is to have the majority of your colored disks face up on the board at the end of the game.\n Setup. Layout the board and place 4 disks, 2 white side up and 2 black side up in the center of the board as shown.\n Give each player 30 disks. 1 player plays as white and the other as black.\n The player playing black goes first, then turns alternate.\n"
            " On your turn you must place 1 disk on any empty space on the board and outflank your opponent.\n To outflank, means to have your disks on either side of a continuous straight line of your opponent’s disks.\n This line can be any number of disks long and can horizontal, vertical, or diagonal.\n When you place a disk so that you have outflanked your opponent's disks,\n you then flip the outflanked disks over to your color.\n You are allowed to outflank multiple lines in a single turn.\n"
            " If you are unable to outflank your opponent on your turn, then you are not allowed to play and you must skip your turn.\n If you can play, then you must play. Disks may only be outflanked as a direct result of a move and must be in a direct line of the placed disk.\n In this example these 2 white disks are not flipped. An outflank may not skip over your own colored disk to outflank more disks.\n Only the disks in the immediate outflank are captured.\n"
            " All outflanked disks must be flipped. You may not chose to only flip some of them.\n If you flip over the wrong disk, and your opponent hasn’t moved yet, you may fix the error.\n If your opponent has already moved, then you may not fix the error.\n Once a disk is placed on a square it may never be removed or moved to another square.\n If you run out of disks to place, and you still have a legal move, then your opponent must give you some of theirs to use.\n When it is no longer possible for either player to move, the game is over.\n"
            " Disks are counted and the player with the majority of their color showing is the winner.\n You can also play multiple rounds and track points.\n The winner of the round receives points equal to the difference between the number of their opponent’s disks, subtracted from the number of their disks.\n Once players reach a predetermined point total, the game ends and the player with the most points is the winner.\n"
            " There is an advantage to going first. For less experienced players to play with more experienced players,\n the less experienced player can go first. If you need a greater handicap,\n then the less experienced player may start the game with up to 4 disks\n already in play, one in corner of the board.\n";
            cout<<"\nOptions\n"<<endl;
            cout<<"> 1.Return\n"<<endl;
            char op;
            while(1){
                cout<<"Enter : ";
                cin>>op;
                while(!isdigit(op)){
                    cout<<"Enter a valid option\nEnter : ";
                    cin>>op;
                }
                switch(op){
                    case '1':
                        system("cls");
                        return;
                    default:
                        cout<<"Enter a valid option\nEnter : ";
                        continue;
                        break;  
                }
            }
        }
        bool checkLegal(char coin){
            //lXl(10 x 10) === x X y(8x8) board mapping
            //if you put the coin at [li][lj] is it legal or not;
            //if it will result in zero flips illegal or else legal
            if(board[li][lj]!= '-')
                return false;
            
            int countflips=0;
            int flips;
            //direction ->
            int y=lj+1;
            flips=0;
            while(y<l-1){
                if(board[li][y]=='-' ||board[li][y]==coin )
                    break;
                flips++;
                y++;
            }
            if(board[li][y]==coin && flips>0)
                return true;
            //end
            //direction <-
            y=lj-1;
            flips=0;
            while(y>0){
                if(board[li][y]=='-' ||board[li][y]==coin )
                    break;
                flips++;
                y--;
            }
            if(board[li][y]==coin && flips>0)
                return true;
            //end
            //direction down
            int x=li+1;
            flips=0;
            while(x<l-1){
                if(board[x][lj]=='-' ||board[x][lj]==coin )
                    break;
                flips++;
                x++;
            }
            if(board[x][lj]==coin && flips>0)
                return true;
            //end
            //direction up
            x=li-1;
            flips=0;
            while(x>0){
                if(board[x][lj]=='-' ||board[x][lj]==coin )
                    break;
                flips++;
                x--;
            }
            if(board[x][lj]==coin && flips>0)
                return true;
            //end
            //direction /up
            x=li-1;
            y=lj+1;
            flips=0;
            while(x>0 && y<l-1){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x--;
                y++;
            }
            if(board[x][y]==coin && flips>0)
                return true;
            //end
            //direction /down
            x=li+1;
            y=lj-1;
            flips=0;
            while(x<l-1 && y>0){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x++;
                y--;
            }
            if(board[x][y]==coin && flips>0)
                return true;
            //end
            //direction \up
            x=li-1;
            y=lj-1;
            flips=0;
            while(x>0 && y>0){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x--;
                y--;
            }
            if(board[x][y]==coin && flips>0)
                return true;
            //end
            //direction \down
            x=li+1;
            y=lj+1;
            flips=0;
            while(x<l-1 && y<l-1){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x++;
                y++;
            }
            if(board[x][y]==coin && flips>0)
                return true;
            //end
            return false;
        }
        void place(char coin){
            //lXl(10 x 10) === x X y(8x8) board mapping
            //if you put the coin at [li][lj] is it legal or not;
            //if it will result in zero flips illegal or else legal
            int flips,ptr;
            //direction ->
            int y=lj+1;
            flips=0;
            while(y<l-1){
                if(board[li][y]=='-' ||board[li][y]==coin )
                    break;
                flips++;
                y++;
            }
            if(board[li][y]==coin && flips>0)
                for(ptr=lj;ptr<=y;ptr++)
                    board[li][ptr]=coin;
            //end
            //direction <-
            y=lj-1;
            flips=0;
            while(y>0){
                if(board[li][y]=='-' ||board[li][y]==coin )
                    break;
                flips++;
                y--;
            }
            if(board[li][y]==coin && flips>0)
                for(ptr=lj;ptr>=y;ptr--)
                    board[li][ptr]=coin;
            //end
            //direction down
            int x=li+1;
            flips=0;
            while(x<l-1){
                if(board[x][lj]=='-' ||board[x][lj]==coin )
                    break;
                flips++;
                x++;
            }
            if(board[x][lj]==coin && flips>0)
                for(ptr=li;ptr<=x;ptr++)
                    board[ptr][lj]=coin;
            //end
            //direction up
            x=li-1;
            flips=0;
            while(x>0){
                if(board[x][lj]=='-' ||board[x][lj]==coin )
                    break;
                flips++;
                x--;
            }
            if(board[x][lj]==coin && flips>0)
                for(ptr=li;ptr>=x;ptr--)
                    board[ptr][lj]=coin;
            //end
            int ptrx,ptry;
            //direction /up
            x=li-1;
            y=lj+1;
            flips=0;
            while(x>0 && y<l-1){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x--;
                y++;
            }
            if(board[x][y]==coin && flips>0)
                for(ptrx=li,ptry=lj;ptrx>=x && ptry<=y;ptrx--,ptry++)
                    board[ptrx][ptry]=coin;
            //end
            //direction /down
            x=li+1;
            y=lj-1;
            flips=0;
            while(x<l-1 && y>0){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x++;
                y--;
            }
            if(board[x][y]==coin && flips>0)
                for(ptrx=li,ptry=lj;ptrx<=x && ptry>=y;ptrx++,ptry--)
                    board[ptrx][ptry]=coin;
            //end
            //direction \up
            x=li-1;
            y=lj-1;
            flips=0;
            while(x>0 && y>0){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x--;
                y--;
            }
            if(board[x][y]==coin && flips>0)
                for(ptrx=li,ptry=lj;ptrx>=x && ptry>=y;ptrx--,ptry--)
                    board[ptrx][ptry]=coin;
            //end
            //direction \down
            x=li+1;
            y=lj+1;
            flips=0;
            while(x<l-1 && y<l-1){
                if(board[x][y]=='-' ||board[x][y]==coin )
                    break;
                flips++;
                x++;
                y++;
            }
            if(board[x][y]==coin && flips>0)
                for(ptrx=li,ptry=lj;ptrx<=x && ptry<=y;ptrx++,ptry++)
                    board[ptrx][ptry]=coin;
            //end
        }
        int player_move(char key,int turn){
            char coin='0';
            if(turn)
                coin='O';
            switch(key){
                case 'w':
                    if(board[li-1][lj] == '-' || board[li-1][lj] == '+')
                        li=li-1;
                    break;
                case 's':
                    if(board[li+1][lj] == '-' || board[li+1][lj] == '+')
                        li=li+1;
                    break;
                case 'a':
                    if(board[li][lj-1] == '-' || board[li][lj-1] == '+')
                        lj=lj-1;
                    break;
                case 'd':
                    if(board[li][lj+1] == '-' || board[li][lj+1] == '+')
                        lj=lj+1;
                    break;
                case 'x':
                    if(checkLegal(coin)){
                        place(coin);
                        return 1;
                    }
                    else
                        return -1;
                    break;
                default:
                    cout<<"ENTER MOVE : w,s,a,d,x"<<endl;
                    break;
            }
            return 0;
        }
        void set_board(){
            coins=64;
            for(int i=0;i<l;i++){
                for(int j=0;j<l;j++){
                    if(i==0 || i==l-1)
                        board[i][j]='+';
                    else if(j==0 || j==l-1)
                            board[i][j]='+';   
                    else 
                        board[i][j]='-';
                }    
            }
            board[0][0]='#';
            board[l/2-1][l/2-1]='0';
            board[l/2-1][l/2]='O';
            board[l/2][l/2-1]='O';
            board[l/2][l/2]='0';
            coins-=4;
        }
        string winner(){
            int pl1=0,pl2=0;
            for(int i=0;i<l;i++){
                for(int j=0;j<l;j++){
                    if(board[i][j]=='0')
                        pl1++;
                    else if(board[i][j]=='O')
                        pl2++;
                }    
            }
            if(pl1>pl2)
                return "Player 1 (coins 0) WINS\n";
            else if(pl2>pl1)
                return "Player 2 (coins O) WINS\n";
            else
                return "Draw \n";
        }
        void start(){
            set_board();
            display_board();
            int turn=0;
            li=0,lj=0;
            while(1){
                cout<<"\nPlayer "<<(turn+1);
                if(turn) 
                    cout<<" ( coin O ) ";
                else
                    cout<<" ( coin 0 ) ";
                cout<<" ENTER MOVE : ";
                char input;
                cin>>input;
                system("cls");
                if(isdigit(input)){
                    cout<<"ENTER MOVE : w,s,a,d,x,f"<<endl;
                    continue;    
                }
                if(input == 'f'){
                    cout<<"Counting coins ....\n";
                    break;
                }
                //status 0 turn not over, 1 turn over with legal move , -1 illegal move
                int status=player_move(input,turn); 
                if( status == 0 ){
                    //do nothing
                }
                else if( status == 1 ){
                    turn=!turn;
                    li=0,lj=0;
                    coins--;
                }
                else if( status == -1 ){
                    cout<<"illegal move\n";
                    turn=!turn;
                    li=0,lj=0;
                }
                if(coins==0)
                    break;
                display_board();
            }
            display_board();
            cout<<"\n GAME OVER \n"<<endl;
            cout<<" RESULT : "<<winner()<<endl;
        }

    public:
        void playOthello(){
            char op;
            while(1){
                display_menu();
                cin>>op;
                while(!isdigit(op)){
                    cout<<"Enter a valid option\nEnter : ";
                    cin>>op;
                }
                system("cls");
                switch(op){
                    case '1':
                        start();
                        continue;
                        return;
                    case '2':
                        system("cls");
                        help();
                        break;
                    case '3':
                        return;
                    default:
                        system("cls");
                        continue;
                        break;  
                }
            }
        }
}; 

class Connect4{
    private:
        int l=19;
        int b=8;
        char Board[8][19];
        void setboard(){
            for(int i=0;i<b;i++){
                for(int j=0;j<l;j++){
                    if(j%2==0)
                        Board[i][j]='_';
                    else
                        Board[i][j]='|';
                }    
            }
        }
        void display_board(){
            HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            cout<<"\n\n|1|2|3|4|5|6|7|8|9|10\n";
            for(int i=0;i<b;i++){
                cout<<"|";
                for(int j=0;j<l;j++){
                    if(Board[i][j]=='0')
                    {
                        SetConsoleTextAttribute(h,6 );//turn text yellow
                        cout<<Board[i][j];
                        SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
                    }
                    else if(Board[i][j]=='O')
                    {
                        SetConsoleTextAttribute(h,FOREGROUND_RED );//turn text red
                        cout<<Board[i][j];
                        SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
                    }
                    else
                        cout<<Board[i][j];
                }
                cout<<"|";
                cout<<endl;    
            }
            SetConsoleTextAttribute(h,15);//white        
        }
        void display_menu(){
            printGameBox();
            cout<<"\nCONNECT 4\n\n";
            cout<<"> 1. play\n";
            cout<<"> 2. Help\n";
            cout<<"> 3. Return\n\n";
            cout<<"Enter option : ";
        }
        void help(){
            HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute(h,15);//white
            cout<<"HELP\n"<<endl;
            cout<<"Game Objective\n"<<endl;
            cout<<"> Connect 4 to win\n"<<endl;
            cout<<"Coins\n"<<endl;
            cout<<"> player 1 = ";
            SetConsoleTextAttribute(h,6 );//turn text yellow
            cout<<"0";
            SetConsoleTextAttribute(h,15);//white
            cout<<" coins"<<endl;
            cout<<"> player 2 = ";
            SetConsoleTextAttribute(h,FOREGROUND_RED );//turn text red
            cout<<"O";
            SetConsoleTextAttribute(h,15);//turn text white
            cout<<" coins"<<endl;
            cout<<"\nOptions\n"<<endl;
            cout<<"> 1.Return\n"<<endl;
            char op;
            while(1){
                cout<<"Enter : ";
                cin>>op;
                while(!isdigit(op)){
                    cout<<"Enter a valid option\nEnter : ";
                    cin>>op;
                }
                switch(op){
                    case '1':
                        system("cls");
                        return;
                    default:
                        cout<<"Enter a valid option\nEnter : ";
                        continue;
                        break;  
                }
            }
        }
        int enter(int pno,int c){
            c=(c*2)-2;

            char coin;
            if(pno==1)
                coin='0';
            else 
                coin='O';

            for(int j=b-1 ; j>=0 ;j--){
                if(Board[j][c]=='_'){
                    Board[j][c]=coin;
                    //vertical win
                    if( j<=(b-4) && Board[j][c]==coin && Board[j+1][c]==coin && Board[j+2][c]==coin &&Board[j+3][c]==coin){
                        system("cls");
                        display_board();
                        cout<<"\n\n PLAYER "<<pno<<" WINS VERTICALLY\n"<<endl;
                        return 1;
                    }

                    //horizontal win
                    int l1=c,l2=c+2,l3=c+4,l4=c+6;

                    for(int type=0;type<4;type++){
                        if(l1>=0 && l4<=18 && Board[j][l1]==coin && Board[j][l2]==coin && Board[j][l3]==coin &&Board[j][l4]==coin){
                            system("cls");
                            display_board();
                            cout<<"\n\nPLAYER "<<pno<<" WINS \n"<<endl;
                            return 1;
                        }
                        l1-=2;
                        l2-=2;
                        l3-=2;
                        l4-=2;
                    }
                    //"\"diagonal win
                    int x1=c,x2=c+2,x3=c+4,x4=c+6;
                    int y1=j,y2=j+1,y3=j+2,y4=j+3;

                    for(int y=0;y<4;y++){
                        if( ( x1 >= 0 && y1 >= 0 ) && ( x4 <= 18 && y4 <= 7 ) && ( Board[y1][x1] == coin ) && ( Board[y2][x2] == coin ) && ( Board[y3][x3] == coin ) && ( Board[y4][x4] == coin )){
                            system("cls");
                            display_board();
                            cout<<"\n\n PLAYER "<<pno<<" WINS fwdslash DIAGONALLY\n"<<endl;
                            return 1;
                        }
                        y1-=1;
                        y2-=1;
                        y3-=1;
                        y4-=1;
                        x1-=2;
                        x2-=2;
                        x3-=2;
                        x4-=2;

                    }
                    //"/"diagonal win
                    x1=c,x2=c+2,x3=c+4,x4=c+6;
                    y1=j,y2=j-1,y3=j-2,y4=j-3;
                    for(int y=0;y<4;y++){
                        if(( x1>=0 && y1<b )&& ( x4<=18 && y4>=0 ) && Board[y1][x1]==coin && Board[y2][x2]==coin && Board[y3][x3]==coin && Board[y4][x4]==coin){
                            system("cls");
                            display_board();
                            cout<<"\n\n PLAYER "<<pno<<" WINS backslash DIAGONALLY\n"<<endl;
                            return 1;
                        }
                        y1+=1;
                        y2+=1;
                        y3+=1;
                        y4+=1;
                        x1-=2;
                        x2-=2;
                        x3-=2;
                        x4-=2;
                    }
                    break;
                }
            }
            return 0;
        }
        void start(){
            setboard();
            int player=1;
            int c;
            while(1){
                system("cls");
                display_board();
                cout<<"\nPlayer "<<player<<" enter cloumn : ";
                cin>>c;
                while( c<1 || c>10){
                    cout<<"\nPlayer "<<player<<" enter valid cloumn : ";
                    cin>>c;
                }
                if(Board[0][(c*2)-2]!='_'){
                    continue;
                }
                if(enter(player,c))
                    return;
                if(player==1)
                    player=2;
                else
                    player=1;
            }
        }

    public:

        void playConnect4(){
            char op;
            while(1){
                display_menu();
                cin>>op;
                while(!isdigit(op)){
                    cout<<"Enter a valid option\nEnter : ";
                    cin>>op;
                }
                system("cls");
                switch(op){
                    case '1':
                        start();
                        continue;
                        return;
                    case '2':
                        system("cls");
                        help();
                        break;
                    case '3':
                        return;
                    default:
                        system("cls");
                        continue;
                        break;  
                }
            }
        }
};

void showAbout(){
    printGameBox();
    cout<<"\nAbout\n"<<endl;
    cout<<"> A Collection of Strategic Board Games Made with Passion For Programming\n"<<endl;
    cout<<"Options\n"<<endl;
    cout<<"> 1.Return\n"<<endl;
    char op;
    while(1){
        cout<<"Enter : ";
        cin>>op;
        while(!isdigit(op)){
            cout<<"Enter a valid option\nEnter : ";
            cin>>op;
        }
        switch(op){
            case '1':
                system("cls");
                return;
            default:
                cout<<"Enter a valid option\nEnter : ";
                continue;
                break;  
        }
    }
}

void play(){
    char gameId;
    while(1){
        printGameBox();
        cout<<"\nSELECT GAME\n"<<endl;
        cout<<"> 1. Tic_Tac_Toe"<<endl;
        cout<<"> 2. Othello"<<endl;
        cout<<"> 3. Connect 4"<<endl;   
        cout<<"> 4. Return\n"<<endl;    
        cout<<"Enter : ";
        cin>>gameId;
        while(!isdigit(gameId)){
            cout<<"Enter a valid option\nEnter : ";
            cin>>gameId;
        }
        TicTacToe newTicTacToeGame;
        Othello newOthelloGame;
        Connect4 newConnect4game;
        system("cls");
        switch(gameId){
            case '1':
                newTicTacToeGame.playTicTacToe();
                break;
            case '2':
                newOthelloGame.playOthello();
                break;
            case '3':
                newConnect4game.playConnect4();
                break;
            case '4':
                return;    
            default:
                continue;   
        }
    }
}

void printGameBox(){
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(h,FOREGROUND_BLUE );//turn text blue
    cout<<endl<<
    " ..|'''.|                                   '||''|.                   \n" 
    ".|'     '   ....   .. .. ..     ....         ||   ||    ...   ... ... \n" 
    "||    .... '' .||   || || ||  .|...||        ||'''|.  .|  '|.  '|..'  \n" 
    "'|.    ||  .|' ||   || || ||  ||             ||    || ||   ||   .|.   \n" 
    " ''|...'|  '|..'|' .|| || ||.  '|...'       .||...|'   '|..|' .|  ||. \n" 
    <<endl;
    SetConsoleTextAttribute(h,15);//white        
}