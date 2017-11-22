//Arturo Manrique Garza
//Benjamin Gonzalo Soto Andrade
//Programming Fundamentals Final Project
//Battleships Game
#include<iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include <stdlib.h>
using namespace std;

/*
generateShips
function which spawns the ships in a matrix
parameters: iMatBoard, the matrix to fill up
returns: none
*/
void generateShips(int iMatBoard[][10]){
//calculates the coordinates of the first part of the ship
    int startingX = rand()%10;
    int startingY = rand()%10;
    int direction = 0;
    bool bRepeat = false;
    bool bValid = true;
 // 1 stand for the "charger" ship
    iMatBoard[startingX][startingY] = 1;
 //starts to build the charger
    do{
 //checks if the ship couldnt be placed
        if(bRepeat == true){
 //moves the ship to another location
            do{
 //deletes the previous point
                iMatBoard[startingX][startingY] = 0;
                startingX = rand()%10;
                startingY = rand()%10;
//Checks if the space is available and places the starter point
                if(iMatBoard[startingX][startingY] == 0){
                    iMatBoard[startingX][startingY] = 1;
// allows the loop to end
                    bValid = true;
                }
//continues to find an available space
                else{
                    bValid = false;
                }
            }while(bValid == false);
        }
//resets the control variable
        bRepeat = false;
//randomizes the direction upon which the ship is going to be built
        direction = rand()%4;
        switch(direction){
            case 0:
//checks that there is enough board to the right to build the ship and that every space is empty
                if(startingX < 5 && iMatBoard[startingX +1 ][startingY] == 0
                   && iMatBoard[startingX + 2][startingY] == 0
                   && iMatBoard[startingX + 3][startingY] == 0
                   && iMatBoard[startingX + 4][startingY] == 0){
//builds the ship to the right
                    for(int iCounter = 1; iCounter < 5; iCounter++){
                        iMatBoard[startingX + iCounter][startingY] = 1;
                    }
                }
//if there is no space it sets the variable in order for the loop to do another lap
                else{
                    bRepeat = true;
                }
            break;
            case 1:
// checks that there is enough board to the left to build the ship and that it is empty as well
                if(startingX > 4 && iMatBoard[startingX - 1 ][startingY] == 0
                   && iMatBoard[startingX - 2][startingY] == 0
                   && iMatBoard[startingX - 3][startingY] == 0
                   && iMatBoard[startingX - 4][startingY] == 0){
//builds the ship to the left
                    for(int iCounter = 1; iCounter < 5; iCounter++){
                        iMatBoard[startingX - iCounter][startingY] = 1;
                    }
                }
//if there is not enough space it restarts the loop
                else{
                    bRepeat = true;
                }
            break;
            case 2:
// checks that there is enough board on top to build the ship and that it is empty as well
                    if(startingY < 5 && iMatBoard[startingX][startingY + 1] == 0
                    && iMatBoard[startingX][startingY + 2] == 0
                    && iMatBoard[startingX][startingY + 3] == 0
                    && iMatBoard[startingX][startingY + 4] == 0){
// builds the ship up
                        for(int iCounter = 1; iCounter < 5; iCounter++){
                            iMatBoard[startingX][startingY + iCounter] = 1;
                        }
                    }
//if there is not enough space it restarts the loop
                else{
                    bRepeat = true;
                }
            break;
            case 3:
// checks that there is enough board underneath to build the ship and that it is empty as well
                if(startingY > 4 && iMatBoard[startingX][startingY - 1] == 0
                   && iMatBoard[startingX][startingY - 2] == 0
                   && iMatBoard[startingX][startingY - 3] == 0
                   && iMatBoard[startingX][startingY - 4] == 0){
// builds the ship downwards
                    for(int iCounter = 1; iCounter < 5; iCounter++){
                        iMatBoard[startingX][startingY - iCounter] = 1;
                    }
                }
//forces the loop to restart
                else{
                    bRepeat = true;
                }
            break;
            default:
//Warning of boundary break
                cout << endl << "Unexpected Error (At generating Helicharger)" << endl << endl;
            break;
        }
//if there was no space available restarts the loop
    }while(bRepeat == true);
//------------------------------------------------------------------------------------------------------
//runs the exact same process but fills it with 2s that mean a BattleShip
// the only difference is that it builds 3 spaces instead of 4
    int bEscape = true;
    do{
    bEscape = true;
    startingX = rand()%10;
    startingY = rand()%10;
    if(iMatBoard[startingX][startingY] == 0){
        iMatBoard[startingX][startingY] = 2;
    }
    else{
        bEscape = false;
    }
    }while(bEscape == false);
    do{
        if(bRepeat == true){
            iMatBoard[startingX][startingY] = 0;
            do{
                startingX = rand()%10;
                startingY = rand()%10;
                if(iMatBoard[startingX][startingY] == 0){
                    iMatBoard[startingX][startingY] = 2;
                    bValid = true;
                }
                else{
                    bValid = false;
                }
            }while(bValid == false);
        }
        bRepeat = false;
        direction = rand()%4;
        switch(direction){
            case 0:
                if(startingX < 6 && iMatBoard[startingX +1 ][startingY] == 0
                   && iMatBoard[startingX + 2][startingY] == 0
                   && iMatBoard[startingX + 3][startingY] == 0 ){
                    for(int iCounter = 1; iCounter < 4; iCounter++){
                        iMatBoard[startingX + iCounter][startingY] = 2;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 1:
                if(startingX > 3 && iMatBoard[startingX - 1 ][startingY] == 0
                   && iMatBoard[startingX - 2][startingY] == 0
                   && iMatBoard[startingX - 3][startingY] == 0){
                    for(int iCounter = 1; iCounter < 4; iCounter++){
                        iMatBoard[startingX - iCounter][startingY] = 2;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 2:
                if(startingY < 6 && iMatBoard[startingX][startingY + 1] == 0
                   && iMatBoard[startingX][startingY + 2] == 0
                   && iMatBoard[startingX][startingY + 3] == 0){
                    for(int iCounter = 1; iCounter < 4; iCounter++){
                        iMatBoard[startingX][startingY + iCounter] = 2;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 3:
                if(startingY > 3 && iMatBoard[startingX][startingY - 1] == 0
                   && iMatBoard[startingX][startingY - 2] == 0
                   && iMatBoard[startingX][startingY - 3] == 0){
                    for(int iCounter = 1; iCounter < 4; iCounter++){
                        iMatBoard[startingX][startingY - iCounter] = 2;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            default:
                cout << endl << "Unexpected Error (At generating Battleship)" << endl << endl;
            break;
        }
    }while(bRepeat == true);
//----------------------------------------------------------------------------------------------------
 //runs the exact same process but fills it with 3s that mean a submarine
// the only difference is that it builds 2 spaces instead of 3
    do{
    bEscape = true;
    startingX = rand()%10;
    startingY = rand()%10;
    if(iMatBoard[startingX][startingY] == 0){
        iMatBoard[startingX][startingY] = 3;
    }
    else{
        bEscape = false;
    }
    }while(bEscape == false);
    do{
        if(bRepeat == true){
            iMatBoard[startingX][startingY] = 0;
            do{
                startingX = rand()%10;
                startingY = rand()%10;
                if(iMatBoard[startingX][startingY] == 0){
                    iMatBoard[startingX][startingY] = 3;
                    bValid = true;
                }
                else{
                    bValid = false;
                }
            }while(bValid == false);
        }
        bRepeat = false;
        direction = rand()%4;
        switch(direction){
            case 0:
                if(startingX < 7 && iMatBoard[startingX +1 ][startingY] == 0
                   && iMatBoard[startingX + 2][startingY] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX + iCounter][startingY] = 3;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 1:
                if(startingX > 2 && iMatBoard[startingX - 1 ][startingY] == 0
                   && iMatBoard[startingX - 2][startingY] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX - iCounter][startingY] = 3;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 2:
                if(startingY < 7 && iMatBoard[startingX][startingY + 1] == 0
                   && iMatBoard[startingX][startingY + 2] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX][startingY + iCounter] = 3;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 3:
                if(startingY > 2 && iMatBoard[startingX][startingY - 1] == 0
                   && iMatBoard[startingX][startingY - 2] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX][startingY - iCounter] = 3;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            default:
                cout << endl << "Unexpected Error (At generating Cruiser)" << endl << endl;
            break;
        }
    }while(bRepeat == true);
//---------------------------------------------------------------------------------------
//runs the exact same process but fills it with 4s that mean a Cruiser
// this is the exact same code as above except with 4s
    do{
    bEscape = true;
    startingX = rand()%10;
    startingY = rand()%10;
    if(iMatBoard[startingX][startingY] == 0){
        iMatBoard[startingX][startingY] = 4;
    }
    else{
        bEscape = false;
    }
    }while(bEscape == false);
    do{
        if(bRepeat == true){
        iMatBoard[startingX][startingY] = 0;
            do{
                startingX = rand()%10;
                startingY = rand()%10;
                if(iMatBoard[startingX][startingY] == 0){
                    iMatBoard[startingX][startingY] = 4;
                    bValid = true;
                }
                else{
                    bValid = false;
                }
            }while(bValid == false);
        }
        bRepeat = false;
        direction = rand()%4;
        switch(direction){
            case 0:
                if(startingX < 7 && iMatBoard[startingX +1 ][startingY] == 0
                   && iMatBoard[startingX + 2][startingY] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX + iCounter][startingY] = 4;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 1:
                if(startingX > 2 && iMatBoard[startingX - 1 ][startingY] == 0
                   && iMatBoard[startingX - 2][startingY] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX - iCounter][startingY] = 4;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 2:
                if(startingY < 7 && iMatBoard[startingX][startingY + 1] == 0
                   && iMatBoard[startingX][startingY + 2] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX][startingY + iCounter] = 4;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 3:
                if(startingY > 2 && iMatBoard[startingX][startingY - 1] == 0
                   && iMatBoard[startingX][startingY - 2] == 0){
                    for(int iCounter = 1; iCounter < 3; iCounter++){
                        iMatBoard[startingX][startingY - iCounter] = 4;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            default:
                cout << endl << "Unexpected Error (At generating Submarine)" << endl << endl;
            break;
        }
    }while(bRepeat == true);
//---------------------------------------------------------------------------------------------
//runs the exact same process but fills it with 1s that mean a Destroyer
// the only difference is that it builds 2 spaces instead of 3
    do{
    bEscape = true;
    startingX = rand()%10;
    startingY = rand()%10;
    if(iMatBoard[startingX][startingY] == 0){
        iMatBoard[startingX][startingY] = 5;
    }
    else{
        bEscape = false;
    }
    }while(bEscape == false);
    do{
        if(bRepeat == true){
            iMatBoard[startingX][startingY] = 0;
            do{
                startingX = rand()%10;
                startingY = rand()%10;
                if(iMatBoard[startingX][startingY] == 0){
                    iMatBoard[startingX][startingY] = 5;
                    bValid = true;
                }
                else{
                    bValid = false;
                }
            }while(bValid == false);
        }
        bRepeat = false;
        direction = rand()%4;
        switch(direction){
            case 0:
                if(startingX < 8 && iMatBoard[startingX +1 ][startingY] == 0){
                    for(int iCounter = 1; iCounter < 2; iCounter++){
                        iMatBoard[startingX + iCounter][startingY] = 5;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 1:
                if(startingX > 1 && iMatBoard[startingX - 1 ][startingY] == 0){
                    for(int iCounter = 1; iCounter < 2; iCounter++){
                        iMatBoard[startingX - iCounter][startingY] = 5;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 2:
                if(startingY > 8 && iMatBoard[startingX][startingY + 1] == 0){
                    for(int iCounter = 1; iCounter < 2; iCounter++){
                        iMatBoard[startingX][startingY + iCounter] = 5;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            case 3:
                if(startingY > 2 && iMatBoard[startingX][startingY - 1] == 0){
                    for(int iCounter = 1; iCounter < 2; iCounter++){
                        iMatBoard[startingX][startingY - iCounter] = 5;
                    }
                }
                else{
                    bRepeat = true;
                }
            break;
            default:
                cout << endl << "Unexpected Error (At generating Destroyer)" << endl << endl;
            break;
        }
    }while(bRepeat == true);
}


/*
input
function which reads the input frome the user
parameters: row and column which will be returned
returns: rows and columns of the attack
*/
void input(int &iRow, int &iColumn){
    cout << endl << "Input the coordinates of your attack"<<endl;
    //variable for the coordinates
    string sInput;
    cin>>sInput;
//If the user inputs exit values otherwise unobtainable will be returned
 	if(sInput == "exit"){
//ASCII has 256 characters(including null) therefore 1000 will be unobtainable otherwise
    	iRow = 1000;
     	iColumn = 1000;
    }
 	else if(sInput.length() > 2 && ((sInput[1] == '1' && sInput[2] != '0') ||(sInput[1] != '1'))){
//Just another validation in order to check if it is a valid coordinate
    }
 	else{
    	//gives the "letter" part of the coordinate a numerical value that can be used
    	char cLetters=sInput[0];
    	int iLetters= cLetters-65;
    	//gives the "number" part of the coordinate a numerical value that can be used
    	char cNumbers=sInput[1];
    	int iNumbers= cNumbers-'0';
    	iColumn=iNumbers-1;
    	iRow=iLetters;
    	//checks if the "number" part of the coordinate is a 10
    	if((sInput.length()==3) && (sInput[1]=='1') && sInput[2]=='0') {
        	iColumn=9;
    	}
    }
}

/*
printMatrix
function which prints the board
parameters: cMatrix, the board to be printed
returns: none
*/
void printMatrix(char cMatrix[10][10]){
    //prints the number axis of the coordinate system
    cout<<"  ";
    for(int iCounter=1; iCounter<11; iCounter++){
        cout<<iCounter<<" ";
    }
    cout<<endl;
    //Ascii representation of A
    char cIndex=65;
    //Prints the letter axis of the coordinate system and the game board
    for(int iCounter=0; iCounter<10; iCounter++){
        cout<<cIndex<<" ";
        for(int iSecCounter=0; iSecCounter<10; iSecCounter++){
            cout<<cMatrix[iCounter][iSecCounter]<<" ";
        }
        cIndex++;
        cout<<endl;
    }
}

/*
alterMatrix
function which processes each turn in the game
parameters: The players board, the enemies fleet, the rows and columns of the attack, and every single ship's missing health
            bIsPlayer (wether or not its the players turn, True if it is, false if it isnt)
returns: none
*/
void alterMatrix(char cMatrix[10][10], int iEnemyMatrix[10][10], int iRow, int iColumn, int &iCarrier, int &iBattleship,
                 int &iSubmarine, int &iCruiser, int &iDestroyer, bool bIsPlayer){
//variable which allows the AI to identify repeated shots
 		bool bRepeat = false;
//loop which ensures no shot is repeated
 		do{
//refreshes the condition
         	bRepeat = false;
//checks if the coordinates has been hit before and therefore transformed into a hit or miss
 			if(cMatrix[iRow][iColumn] == 'X' || cMatrix[iRow][iColumn] == 'O'){
//if its not the player turn it fixes the problem itself
                if(bIsPlayer==false){
//randomizes variables again
        	       iRow = rand()%10;
        	       iColumn = rand()%10;
                }
//if it is the players turn it forces the player to change his coordinate
                else{
                    cout << endl <<"Please enter a valid coordinate!!!"<<endl;
                 	cout << "Valid coordinates must have a capital letter (A-J) and a number (1-10)" << endl;
                    cout << "Shooting the same coordinate twice or more is not valid" << endl;
                    input(iRow, iColumn);
                }
//ensures the loop will finish
        	bRepeat = true;
            }
        }while(bRepeat == true);
        //These set of functions add the number of hits a ship has taken
        int iShip=iEnemyMatrix[iRow][iColumn];
        if (iShip==1){
            if(iCarrier<5){
                iCarrier++;
            }
        }
        if (iShip==2){
            if(iBattleship<4){
                iBattleship++;
            }
        }
        if (iShip==3){
            if(iSubmarine<3){
                iSubmarine++;
            }
        }
        if (iShip==4){
            if(iCruiser<3){
                iCruiser++;
            }
        }
        if (iShip==5){
            if(iDestroyer<2){
                iDestroyer++;
            }
        }
        //puts an "X" if a ship is hit and an "O" if the shot misses
        if(iShip==1 || iShip==2 || iShip==3 || iShip==4 || iShip==5){
            cMatrix[iRow][iColumn]='X';
            iEnemyMatrix[iRow][iColumn]=0;
         	cout << "---HIT---" << endl;
        }
        else{
            if(iEnemyMatrix[iRow][iColumn] == 0){
                cMatrix[iRow][iColumn]='O';
             	cout << "---MISS---" << endl;
            }
        }
        printMatrix(cMatrix);
}

/*
Instuctions
Functions which prints the set of instructions
Parameters: none
Returns: none
*/
void instuctions(){
    cout << endl << "------INSTRUCTIONS------" << endl;
    cout << "Battleships is a 2 player board game" << endl;
    cout << "The game is set on a 10 X 10 tile board" << endl;
    cout << "Each side of the board is filled with ships" << endl;
    cout << "Each ship occupies different amounts of tiles" << endl;
    cout << "This game is turned based and does no end untill one player is defeated" << endl;
    cout << "The players take turns in order to shoot a torpedo at each other" << endl;
    cout << "Each torpedo is launched by the player announcing the coordinate it aims for" << endl;
    cout << "Each shot will either be considered as a hit (X) or a miss (O)" << endl;
    cout << "If a ship is hit in all of its tiles it will be considered sunk" << endl;
    cout << "Sink all of the enemy's ships in order to win" << endl << endl;
}

/*
checkIfSunk
functions which determines if a ship sinks and if the game is over
parameters: an array that determines the condition of each ship, every single ships' missing health
returns: bGameOver, if the player won/lost or not yet
*/
bool checkIfSunk(bool bArrSunk[], int iCarrier, int iSubmarine, int iBattleship, int iCruiser, int iDestroyer, bool bIsPlayer){
//starts the returning variable as false
    bool bGameOver = false;
//checks if the Carrier is dead and was not previously determined as sunk
    if(iCarrier == 5 && bArrSunk[0] == false){
// warns the user of a sunken ship
        cout<<endl << endl << "-----BATTLESHIP SUNK-----" << endl << endl;
//makes sure not to repeat the anouncement
        bArrSunk[0] = true;
    }
//checks if the Battlehip was hit for the last time
    else if(iBattleship == 4 && bArrSunk[1] == false){
        cout<<endl << endl << "-----BATTLESHIP SUNK-----" << endl << endl;
        bArrSunk[1] = true;
    }
//Checks if the submarine was hit for the last time
    else if(iSubmarine == 3 && bArrSunk[2] == false){
       cout<< endl << endl << "-----BATTLESHIP SUNK-----" << endl << endl;
        bArrSunk[2] = true;
    }
//checks if the cruiser was hit for the last time
    else if(iCruiser == 3 && bArrSunk[3] == false){
     cout<<endl << endl << "-----BATTLESHIP SUNK-----" << endl << endl;
        bArrSunk[3] = true;
    }
//checks if the destroyer was hit for the last time
    else if(iDestroyer == 2 && bArrSunk[4] == false){
       cout<< endl << endl << "-----BATTLESHIP SUNK-----" << endl << endl;
        bArrSunk[4] = true;
    }
//checks if all ships are sunk and if the player did it
    if( bArrSunk[0] == true &&
        bArrSunk[1] == true &&
        bArrSunk[2] == true &&
        bArrSunk[3] == true &&
        bArrSunk[4] == true &&
        bIsPlayer == true){
//congratulates the player on winning
        cout << endl << endl << "CONGRATULATIONS YOU WON!!!" << endl << endl;
//sets the game to end
        bGameOver = true;
        }
//checks if all ships were sunk by the computer
     else if( bArrSunk[0] == true &&
        bArrSunk[1] == true &&
        bArrSunk[2] == true &&
        bArrSunk[3] == true &&
        bArrSunk[4] == true &&
        bIsPlayer == true){
        cout << endl << endl << "DEFEAT!!!" << endl << endl;
        bGameOver = true;
        }
//returns wether the game should keep going or not
      return bGameOver;
}

/*
menu
Functions which displays the main menu and links related functions
Parameters: none
Returns: bExit, if the user wishes to quit the game
*/
bool menu(){
    bool bGameOver = false;
    bool bExit = false;
    bool bEscape = true;
    int iRow = 0;
    int iColumn = 0;
 //Your ships missing health
    int iCarrier = 0;
    int iSubmarine = 0;
    int iBattleShip = 0;
    int iCruiser = 0;
    int iDestroyer = 0;
//The AI's ship missing health
    int iCarrierAI = 0;
    int iSubmarineAI = 0;
    int iBattleShipAI = 0;
    int iCruiserAI = 0;
    int iDestroyerAI = 0;
    string sSelection = " ";
    string sConfirm = "";
//variables to avoid repetition
int iRepeat=1;
int iRepeatRow[1000];
int iRepeatColumn[1000];
iRepeatRow[0]=-1;
iRepeatColumn[0]=-1;
bool bRepeated;
//The Main Menu
    cout << endl << "Welcome to Battleships" << endl;
    cout << "1.- Instructions" << endl;
    cout << "2.- Play the game" << endl;
    cout << "3.- Exit" << endl;
    cout << "Type the number of the action you wish to perform" << endl << endl;
//Reads the action to do
    cin >> sSelection;
// Analizes the Action based on the first char
    switch(sSelection[0]){
        case('1'):
            instuctions();
            break;
//plays the game
        case('2'):
      		cout << endl << "In order to forfeit type 'exit' on your turn" << endl;
//initializes matrixes for the player and AI
//one determines the players fleets and the other one is the display
            int iMatPlayer[10][10];
            int iMatAI[10][10];
            char cMatPlayer[10][10];
            char cMatAI[10][10];
// arrays that calculate which ships have been sunk
            bool bArrSunk[5];
            bool bArrSunkAI[5];
//initializes the matrixes as their default values
            for(int iRow = 0; iRow < 10; iRow++){
                for(int iColumn = 0; iColumn < 10; iColumn ++){
                    iMatPlayer[iRow][iColumn] = 0;
                    iMatAI[iRow][iColumn] = 0;
                 	cMatPlayer[iRow][iColumn] = '-';
                    cMatAI[iRow][iColumn] = '-';
                }
            }
//initializes the arrays
            for(int iCounter = 0; iCounter < 5; iCounter++){
                    bArrSunk[iCounter] = false;
                    bArrSunkAI[iCounter] = false;
            }
//randomly creates the boards
            generateShips(iMatPlayer);
            generateShips(iMatAI);
//loop which keeps the game running
            do{
//Resets the variables
             	iRow = -1;
             	iColumn = -1;
//warns the player its their turn
                cout << endl <<  "Your turn" << endl;
//prints the players side so a decision can be made
            	printMatrix(cMatPlayer);
//allows the turn of the player
            	input(iRow,iColumn);
             	if(iRow == 1000 && iColumn == 1000){
                	bGameOver = true;
                 	cout << endl << "-----FORFEIT-----" << endl << endl;
                }
//checks if the user decided to forfeit
             	if(bGameOver == false){
            	while((iRow<0 || iRow >9 || iColumn <0 || iColumn>9)){
                        cout << endl <<"Please enter a valid coordinate!!!"<<endl;
                 		cout << "Valid coordinates must have a capital letter (A-J) and a number (1-10)" << endl;
                 		cout << "Example: B7" << endl << endl;
                        input(iRow,iColumn);
            	}
//processes the move and sends a true as a parameter as its the players turn
            	alterMatrix(cMatPlayer, iMatAI, iRow, iColumn, iCarrier, iBattleShip, iSubmarine, iCruiser, iDestroyer,true);
//checks wether or not the game is over
            	bGameOver = checkIfSunk(bArrSunk,iCarrier,iSubmarine,iBattleShip,iCruiser,iDestroyer,true);
                }
//prevent the opponents turn if the player already won
            	if(bGameOver == false){
            		cout << endl << "Press Enter to continue " << endl;
            		cin.ignore();
            		cin.ignore();
//allows the user to see his action before the AI plays his turn
            		cout << endl << "Opponents turn" << endl;
//simulates the decision making by the AI
            		iRow = rand()%10;
            		iColumn = rand()%10;
//checks the move  and sends false as a parameter as its the players turn
            		alterMatrix(cMatAI, iMatPlayer, iRow, iColumn, iCarrierAI, iBattleShipAI, iSubmarineAI, iCruiserAI, iDestroyerAI,false);
//checks if the AI won
            		bGameOver = checkIfSunk(bArrSunkAI,iCarrierAI,iSubmarineAI,iBattleShipAI,iCruiserAI,iDestroyerAI,false);
            		cout << endl << "Press Enter to continue " << endl;
//gives the player time to analyze the opponents move
           			cin.ignore();
            	}
//keeps the game running
            }while(bGameOver == false);
        break;
//Option 3 decides to exit the game
        case('3'):
//This loop provides a second chance to undo the exit selection
            do{
//resets the variable
                bEscape = true;
//checks if it it the first time entering
                if(sConfirm != "yes" && sConfirm != "no"){
                    cout << endl << "Are you sure you wish to exit" << endl << "Type yes or no" << endl << endl;
                    cin >> sConfirm;
                }
//if retriggered it allows the user to exit
                if(sConfirm == "yes"){
                    bExit = true;
                    cout << endl << "THANKS FOR PLAYING BATTLESHIPS";
                }
// calls the function again in order to refresh the menu
                else if (sConfirm == "no"){
                    bExit = menu();
                }
//This option establishes that in order to allow the user to do anything else
// he/she must first input a valid answer
                else{
                    cout << endl << "Unvalid answer, please refrase your answer" << endl;
// makes the loop do an extra round (so it functions properly (yes would not work otherwise))
                    bEscape = false;
                }
// Cheks if it was inputted on the first try
            }while(bEscape == false);
        break;
        default: break;
        }
    return bExit;
}

/*
keepMenuRunning
function which traps the menu in a loop
parameters: none
returns: none
*/
void keepMenuRunning(){
    bool bExit = false;
    do{
//keeps the menu running forever untill told otherwise
        bExit = menu();
    }while(bExit == false);
}

/*
main
Function which calls the main loop function in the program
Parameters: none
Returns: 0 if there are no errors.
*/
int main(){
    keepMenuRunning();
    return 0;
}
