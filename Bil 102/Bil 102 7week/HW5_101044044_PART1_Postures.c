#include "Postures.h"



/*
* Change the Character to front state posture
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
* Sola bakan pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Saga bakan pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Saga yururken ayagin indirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Saga yururken arka ayagin kaldirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Sag yururken ayaklarin vucudun merkezine en yakin kaldirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Saga yururken on ayagin kaldirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Sola yururken ayagin indirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Sola yururken ayagin indirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Sola yururken ayaklarin vucudun merkezine en yakin kaldirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
* Sola yururken sag ayagin kaldirildigi pozisyon.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
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
/*
* Function Objective
* Ziplama pozisyonu1, yerden guc alma.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
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
/*
* Function Objective
* Ziplama pozisyonu2, havaya sicrama.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
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
/*
* Function Objective
* Ziplama pozisyonu3, yere inis.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
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
/*
* Function Objective
* Kollarin yana acilma pozisyonu.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
void zeybek1(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
	character[6][0]=TEXTURE;
	character[6][1]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
	character[6][5]=TEXTURE;
	character[6][6]=TEXTURE;
    character[7][3]=TEXTURE;
    character[8][3]=TEXTURE;
	character[8][4]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][5]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][5]=TEXTURE;
    character[11][1]=TEXTURE;
	character[11][2]=TEXTURE;
	character[11][5]=TEXTURE;
}
/*
* Function Objective
* Ayagin zeybek oynama duzenine gore degistirilmesi.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
void zeybek2(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
	character[6][0]=TEXTURE;
	character[6][1]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
	character[6][5]=TEXTURE;
	character[6][6]=TEXTURE;
    character[7][3]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][4]=TEXTURE;
    character[10][2]=TEXTURE;
    character[10][4]=TEXTURE;
    character[11][1]=TEXTURE;
	character[11][2]=TEXTURE;
	character[11][4]=TEXTURE;
}
/*
* Function Objective
* Arka ayagin havaya kaldirilmasi.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
void zeybek3(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][3]=TEXTURE;
	character[6][0]=TEXTURE;
	character[6][1]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
	character[6][5]=TEXTURE;
	character[6][6]=TEXTURE;
    character[7][3]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][4]=TEXTURE;
	character[10][0]=TEXTURE;
    character[10][1]=TEXTURE;
    character[10][4]=TEXTURE;
	character[11][4]=TEXTURE;
}
/*
* Function Objective
* Kollarin yana acilip, yere diz cokme pozisyonu.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
void zeybek4(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[4][6]=TEXTURE;
    character[5][3]=TEXTURE;
	character[5][5]=TEXTURE;
	character[6][1]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[7][3]=TEXTURE;
    character[8][0]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][2]=TEXTURE;
    character[9][4]=TEXTURE;
	character[10][0]=TEXTURE;
    character[10][1]=TEXTURE;
    character[10][4]=TEXTURE;
	character[11][4]=TEXTURE;
}
/*
* Function Objective
* Sola dogru hareketde arka ayagin bukulmesi.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
void zeybek5(char character[][WIDTH])
{
    character[4][3]=TEXTURE;
    character[5][2]=TEXTURE;
	character[5][4]=TEXTURE;
	character[6][1]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][6]=TEXTURE;
    character[7][2]=TEXTURE;
    character[7][3]=TEXTURE;
    character[7][4]=TEXTURE;
    character[7][5]=TEXTURE;
    character[8][0]=TEXTURE;
    character[8][1]=TEXTURE;
    character[8][3]=TEXTURE;
    character[9][3]=TEXTURE;
	character[10][2]=TEXTURE;
    character[10][4]=TEXTURE;
    character[10][5]=TEXTURE;
	character[11][1]=TEXTURE;
	character[11][2]=TEXTURE;
	character[11][5]=TEXTURE;
}
/*
* Function Objective
* Bitirme hareketi kollarin havaya kaldirilmasi.
* Pre:  Iki boyutlu character string alir.
* Post: String'in icerigi, verilen degerlere gore degistirilir.
*/
void zeybek6(char character[][WIDTH])
{
    character[3][3]=TEXTURE;
    character[4][2]=TEXTURE;
    character[4][4]=TEXTURE;
    character[5][0]=TEXTURE;
    character[5][3]=TEXTURE;
    character[5][6]=TEXTURE;
    character[6][1]=TEXTURE;
    character[6][2]=TEXTURE;
    character[6][3]=TEXTURE;
    character[6][4]=TEXTURE;
    character[6][5]=TEXTURE;
    character[7][3]=TEXTURE;
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
