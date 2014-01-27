/* "if not defined" Eger POSTURES tanimlanmamissa #endif e kadar olan
	bolumu, derleme islemine dahil et. */

#ifndef POSTURES_H_INCLUDED 
#define POSTURES_H_INCLUDED

/* Dimension of the character array */
#define HEIGHT 12
#define WIDTH 7

/* Texture shape of the character */
#define TEXTURE 'o'

/* State Postures */
void frontPosture(char [][WIDTH]);
void leftPosture(char [][WIDTH]);
void rightPosture(char [][WIDTH]);

/* Right Motion Postures */
void toRightFootsDown(char [][WIDTH]);
void toRightBeckFootUp(char [][WIDTH]);
void toRightCenteral(char [][WIDTH]);
void toRightFrontFootUp(char [][WIDTH]);

/* Left Motion Postures */
void toLeftFootsDown(char [][WIDTH]);
void toLeftBeckFootUp(char [][WIDTH]);
void toLeftRightFootUp(char [][WIDTH]);
void toLeftCenteral(char [][WIDTH]);


void jump1(char character[][WIDTH]);
void jump2(char character[][WIDTH]);
void jump3(char character[][WIDTH]);

/* Zeybek Function */
void zeybek1(char character[][WIDTH]);
void zeybek2(char character[][WIDTH]);
void zeybek3(char character[][WIDTH]);
void zeybek4(char character[][WIDTH]);
void zeybek5(char character[][WIDTH]);
void zeybek6(char character[][WIDTH]);

#endif /* POSTURES_H_INCLUDED */

