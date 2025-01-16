#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
int points = 0;
int fruit_x; int fruit_y;
char arr[4][11] = {
    "           "
 ,  "           "
 ,  "           "
 ,  "           "};
 //////////////////////////////////////////////////////////////
 ////////////////////////////////////(//////////////////////////

void generateFruit(){
  fruit_x = rand() % 5;
  fruit_y = rand() % 13;
  if(fruit_x >= 4 || fruit_y >= 11){
      fruit_x = 2;
      fruit_y = 10;
  }
  while(arr[fruit_x][fruit_y] != ' '){
    fruit_x = rand() % 3;
    fruit_y = rand() % 11;
  }
  arr[fruit_x][fruit_y] = 'F';
}
 void map(){
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 11; y++){
            if(arr[x][y] == 'F'){
                 printf("\033[31mF\033[0m"); // Print 'F' in red
            }
            else{
            printf("%c",arr[x][y]);
            }
        }
        printf("\n");
    }
 }
  int fruit_x;
  int fruit_y;
///////////////////////////////s
    ////////////////////////////////
int main(){
    system("cls");
    srand(time(NULL));     
    int snake_x = 1; int snake_y = 5;
    printf("x = %d y = %d\n",snake_x,snake_y);
    map();
    generateFruit();
     void Movedown(){
    snake_x++;
    arr[snake_x][snake_y] = '*';
 }
  void Moveup(){
    snake_x--;
    arr[snake_x][snake_y] = '*';
 }
  void Moveright(){
    snake_y++;
    arr[snake_x][snake_y] = '*';
 }
  void Moveleft(){
    snake_y--;
    arr[snake_x][snake_y] = '*';
 }
    while(1){
         int a = getch();
        switch(a){
            case 'a':
           if(snake_y > 0){
           arr[snake_x][snake_y] = ' ';
           Moveleft();
             if(snake_x == fruit_x && snake_y == fruit_y){
                points++;
                generateFruit();
            }
           }
            break;
            case 'd':
            if(snake_y < 10){
                arr[snake_x][snake_y] = ' ';
               Moveright();
                 if(snake_x == fruit_x && snake_y == fruit_y){
                points++;
                     generateFruit();
            }
           }
            break;
           case 'w':
           if(snake_x > 0){
            arr[snake_x][snake_y] = ' ';
            Moveup();
              if(snake_x == fruit_x && snake_y == fruit_y){
                points++;
                     generateFruit();
            }
           }
           break;
           case 's':
           if(snake_x < 3){
            arr[snake_x][snake_y] = ' ';
            Movedown();
            if(snake_x == fruit_x && snake_y == fruit_y){
                points++;
             generateFruit();
            }
           }
           break;
         }
        system("cls");
        printf("x = %d y = %d\n",snake_x,snake_y);
        printf("points = %d\n",points);
        map();
    }
return 0;
}