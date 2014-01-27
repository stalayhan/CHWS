#include "Postures.h"





/*
* Change the Character to fornt state posture
* Pre:  character[][WIDTH] should be initialized
*       global parameters are defined
* Post: character[][WIDTH] is modified
*/
void frontPosture(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][1]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][5]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][4]=TEXTURE;
    character[11][1]=TEXTURE;
    character[11][2]=TEXTURE;
    character[11][4]=TEXTURE;
    character[11][5]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void leftPosture(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][3]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][3]=TEXTURE;
    character[10][3]=TEXTURE;
    character[11][2]=TEXTURE;
    character[11][3]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void rightPosture(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][3]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][3]=TEXTURE;
    character[10][3]=TEXTURE;
    character[11][3]=TEXTURE;
    character[11][4]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toRightFootsDown(char character[][WIDTH])
{
    character[4][3]=TEXTURE;
    character[5][2]=TEXTURE;
    character[5][4]=TEXTURE;
    character[6][3]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[7][5]=TEXTURE;
    character[8][1]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][3]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][5]=TEXTURE;
    character[11][1]=TEXTURE;
    character[11][5]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toRightBeckFootUp(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][5]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][3]=TEXTURE;
    character[10][1]=TEXTURE;
    character[10][3]=TEXTURE;
    character[11][3]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toRightCenteral(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][3]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][3]=TEXTURE;
    character[11][3]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toRightFrontFootUp(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][1]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[8][3]=TEXTURE;
    character[8][4]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][5]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][5]=TEXTURE;
    character[11][2]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toLeftFootsDown(char character[][WIDTH])
{
    character[4][3]=TEXTURE;
    character[5][2]=TEXTURE;
    character[5][4]=TEXTURE;
    character[6][3]=TEXTURE;
    character[7][1]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[8][3]=TEXTURE;
    character[8][5]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][3]=TEXTURE;
    character[10][1]=TEXTURE;
    character[10][4]=TEXTURE;
    character[11][1]=TEXTURE;
    character[11][5]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toLeftBeckFootUp(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][1]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][3]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][3]=TEXTURE;
    character[10][5]=TEXTURE;
    character[11][3]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toLeftCenteral(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][3]=TEXTURE;
    character[10][3]=TEXTURE;
    character[10][4]=TEXTURE;
    character[11][3]=TEXTURE;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void toLeftRightFootUp(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][5]=TEXTURE;
    character[8][2]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][1]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][1]=TEXTURE;
    character[10][4]=TEXTURE;
    character[11][4]=TEXTURE;
}


void jump1(char character[][WIDTH])
{
    character[4][3]=TEXTURE;
    character[5][2]=TEXTURE;
    character[5][4]=TEXTURE;
    character[6][3]=TEXTURE;
    character[7][1]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[7][5]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][3]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][4]=TEXTURE;
    character[11][1]=TEXTURE;
    character[11][2]=TEXTURE;
    character[11][4]=TEXTURE;
    character[11][5]=TEXTURE;
}

void jump2(char character[][WIDTH])
{
    character[2][3]=TEXTURE;
    character[3][2]=TEXTURE;
    character[3][4]=TEXTURE;
    character[4][3]=TEXTURE;
    character[5][2]=TEXTURE;
    character[5][3]=TEXTURE;
    character[5][4]=TEXTURE;
    character[6][1]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][5]=TEXTURE;
    character[7][3]=TEXTURE;
    character[8][2]=TEXTURE;
    character[8][4]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][4]=TEXTURE;
    character[11][1]=TEXTURE;
    character[11][5]=TEXTURE;
}

void jump3(char character[][WIDTH])
{
    character[0][3]=TEXTURE;
    character[1][2]=TEXTURE;
    character[1][4]=TEXTURE;
    character[2][3]=TEXTURE;
    character[3][2]=TEXTURE;
    character[3][3]=TEXTURE;
    character[3][4]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][3]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][4]=TEXTURE;
    character[8][2]=TEXTURE;
    character[8][4]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][4]=TEXTURE;
}
