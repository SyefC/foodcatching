#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
///////////////////////////////////////////////////////////
char arr[5][20] ={
   "                   ",
   "                   ",
   "                   ",
   "                   ",
   "                   "
};
int x;
int y;
int player_y = 0;
int player_x = 0;

int point = 0;

void MoveR(){
    if(player_y < 19){
        arr[player_x][player_y] = ' ';
        player_y++;
        arr[player_x][player_y] = '>';
    }
}

void MoveL(){
    if(player_y > 0){
        arr[player_x][player_y] = ' ';
        player_y--;
        arr[player_x][player_y] = '<';
    }
}

void MoveD(){
    if(player_x < 4){
        arr[player_x][player_y] = ' ';
        player_x++;
        arr[player_x][player_y] = '|';
    }
}

void MoveU(){
    if(player_x > 0){
        arr[player_x][player_y] = ' ';
        player_x--;
        arr[player_x][player_y] = '^';
    }
}

void generatefood(){
     x = rand() % 5;
     y = rand() % 22;
     if(y > 19){
             x = rand() % 5;
             y = rand() % 22;
     }
    if(arr[x][y] != ' '){
        if(y > 19){
             x = rand() % 5;
             y = rand() % 22;
     }
     else{
 x = rand() % 5;
y = rand() % 22;
     }
    }
    arr[x][y] = 'F';
}

void generatemap(){
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 20; y++){
            if(arr[x][y] == 'O'){
                system("color 1");
            }
            else{
            printf("%c",arr[x][y]);
            }
        }
        printf("\n");
    }
}
    int main(){
        srand(time(NULL));
        generatefood();
        generatemap();
     while(1){
        int a = getch(); 
        switch(a){
            case 'd':
            MoveR();
            if(player_x == x && player_y == y){
                point++;
                generatefood();
            }
            break;
            case 'a':
            MoveL();
             if(player_x == x && player_y == y){
                point++;
                generatefood();
            }
            break;
            case 's':
            MoveD();
             if(player_x == x && player_y == y){
                point++;
                generatefood();
            }
            break;
            case 'w':
            MoveU();
             if(player_x == x && player_y == y){
                point++;
                generatefood();
            }
            break;
            case ';':
            return 0;
        }
        system("cls");
        printf("Location: x = %d y = %d",player_x,player_y);
        printf("points = %d\n",point);
        generatemap();
     }
     return 0;
    }
