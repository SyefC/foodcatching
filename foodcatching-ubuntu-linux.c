#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

///////////////////////////////////////////////////////////
char arr[5][20] = {
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

// Functions to move the player
void MoveR() {
    if (player_y < 19) {
        arr[player_x][player_y] = ' ';
        player_y++;
        arr[player_x][player_y] = '>';
    }
}

void MoveL() {
    if (player_y > 0) {
        arr[player_x][player_y] = ' ';
        player_y--;
        arr[player_x][player_y] = '<';
    }
}

void MoveD() {
    if (player_x < 4) {
        arr[player_x][player_y] = ' ';
        player_x++;
        arr[player_x][player_y] = '|';
    }
}

void MoveU() {
    if (player_x > 0) {
        arr[player_x][player_y] = ' ';
        player_x--;
        arr[player_x][player_y] = '^';
    }
}

// Function to generate food at a random position
void generatefood() {
    do {
        x = rand() % 5;
        y = rand() % 20;
    } while (arr[x][y] != ' ');  // Ensure that food does not overwrite an existing symbol
    arr[x][y] = 'F';
}

// Function to display the game map
void generatemap() {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 20; y++) {
            printf("%c", arr[x][y]);
        }
        printf("\n");
    }
}

// Function to get a single character without pressing Enter
int getch_noblock() {
    struct termios oldt, newt;
    int ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Apply new settings

    ch = getchar();   // Get the character input
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore old settings
    
    return ch;  // Return the character
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    generatefood();     // Generate the first food
    generatemap();      // Print the initial map

    while (1) {
        int a = getch_noblock();  // Use the custom getch_noblock function

        // Clear the screen (Linux equivalent of system("cls"))
        system("clear");

        // Process player input
        switch (a) {
            case 'd':
                MoveR();
                break;
            case 'a':
                MoveL();
                break;
            case 's':
                MoveD();
                break;
            case 'w':
                MoveU();
                break;
            case ';':  // Exit on semicolon
                return 0;
        }

        // Check if player has reached food
        if (player_x == x && player_y == y) {
            point++;
            generatefood();  // Generate new food
        }

        // Display current game status
        printf("Location: x = %d y = %d\n", player_x, player_y);
        printf("Points = %d\n", point);
        generatemap();  // Print the updated game map
    }

    return 0;
}