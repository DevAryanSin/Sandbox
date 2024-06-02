#include <iostream>
#include <conio.h> // Console Commands
#include <windows.h> // Windows API Library
#include <string>
using namespace std;
// using namespace 

// Height and width of the boundary
const int width = 80;
const int height = 20;
char playerName;
// Snake head Coordinates
int x ,y ;
// Food coordinates
int fruitCordX, fruitCordY;
//variable to store the score of the player
int playerScore;
//variable to store the length of the snake's tail
int snakeTailLen;
// Array to store the snake coordinates
int snakeTailX[100], snakeTailY[100];
// for storing sanke's moving direction
enum snakesDirection { STOP = 0, LEFT , RIGHT , UP , DOWN};
//SNAKESDIRECTION VARIABLE 
snakesDirection sDir;
//boolean variable for checking game is over or not
bool isGameOver;

//*****************************************************

//Initializing the game
void GameInit()
{
    isGameOver = false;
    sDir = STOP;
    x = width/2;
    y = height/2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
        
}

//****************************************************
//Function for creating the game board and rendering
void GameRender(string playerName)
{
    system("cls");// Clear the console
    //Creating top walls with '-'

    for (int i = 0; i < width + 2; i++)
        cout<<"-";
     cout<< endl;      


for (int i =0; i <height; i++){
    for (int j = 0; j <= width; j++ ){
        //Creating side walls with '|'
        if (j== 0 || j== width)
            cout << "|";
        // Creating the sanke head with o
        if (i== y && j== x)
        cout << "0";//head
        //Creating the food with #
        else if (i == fruitCordY && j == fruitCordX)
        cout << "#";

    // Creating Snake's head with 'O'
    else{
        bool prTail = false;
        for (int k = 0; k < snakeTailLen; k++){

            if (snakeTailX[k] == j && snakeTailY[k] == i){
                cout << "o"; //tail
                prTail = true;
            }
        }

        if (!prTail)
            cout << " ";

        }
    }
    cout << endl;

}

//Creating bottom walls with '-'

for (int i = 0; i < width + 2; i++)
    cout << "-";
cout << endl;

//Display player's score

cout << playerName << "'s Score: " << playerScore << endl;

}

// Function for updating the game state

void UpdateGame()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    
    for (int i = 1; i < snakeTailLen; i++){
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (sDir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;    
    }

    //Checks for snake's collision with the wall (|)
    if (x>= width || x<0 || y >= height || y < 0)
        isGameOver= true;

    // Check for collsion with the tail (o)
    for (int i = 0 ; i < snakeTailLen; i++){
        if (snakeTailX[i] == x && snakeTailY[i] == y)
        isGameOver= true;
    }    
// Checks for snake's collision with the food (#)

    if (x == fruitCordX && y == fruitCordY){
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }

}

// Function to set the game difficulty level
int SetDifficulty(){

    int dfc, choice;
    cout << "\n SET difficulty \n1: Easy\n 2:Medium\n 3: Hard"
        "\n NOTE: if not chosen or pressed any other"
        "key, the difficulty will be automatically set"
        "to medium \n Choose difficulty level: ";

    cin >> choice;
switch (choice){
    case '1':
        dfc = 50;
        break;
    case '2':
        dfc = 100;
        break;
    case '3':
        dfc = 150;
        break;
    default:
        dfc = 100;
    }
    return dfc;
}

// Function to handle user UserInput

void UserInput()
{
    // Checks if a key is pressed or not
    if (_kbhit()){
        //Getting the pressed Key
        switch (_getch()){
            case 'a':
                sDir = LEFT;
                break;
            case 'd':
                sDir = RIGHT;
                break;
            case 'w':
                sDir = UP;
                break;
            case 's':
                sDir = DOWN;
                break;
            case 'x':
                isGameOver = true;
                break;
        }
    }
}

// Main function / game looping function

int main()
{
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    int dfc = SetDifficulty();


    GameInit();
    while (!isGameOver){
        GameRender(playerName);
        UserInput();
        UpdateGame();
        // creating a delay for according to the chose
        //difficulty
        Sleep(dfc);
    }
    return 0;
}
