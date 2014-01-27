/*################################################################*/
/* HW06_101044044_part2.c                                         */
/* ----------------------                                         */
/* Created on 06.05.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* Belirtilen labirentin cikis yolunu bulur.Labirentin ilk ve son */
/* halini ekrana basar.                                           */
/*################################################################*/

/*----------------------------------------------------------------*/
/*                           Includes                             */
/*----------------------------------------------------------------*/
#include <stdio.h>

#define FALSE 0
#define TRUE 1

#define NROWS 8
#define MCOLS 8

/*########################## Isaretler ###########################*/
/*  '.' = acik                                                    */
/*  '#' = kapali                                                  */
/*  'S' = start                                                   */
/*  'F' = finish                                                  */
/*  '+' = yol                                                     */
/*  'x' = yanlis yol                                              */
/*################################################################*/
char maze[NROWS][MCOLS] = {
	".S..####",
	"#.#....#",
	"#.##.#..",
	"..#.###.",
	"#.......",
	"#.#..###",
	"#.#...#.",
	"....#..F"
};
/*----------------------------------------------------------------*/
/*                     Function Prototypes                        */
/*----------------------------------------------------------------*/
void display_maze(void);
int find_path(int x, int y);
/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int
main(void)
{
	display_maze();

	if ( find_path(0, 0) == TRUE )
		printf("This is correct path!\n");
	else
		printf("There is no path!\n");

	display_maze();

	return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function display_maze                                          */
/*--------------------                                            */
/* Maze i ekrana basar.                                           */
/*----------------------------------------------------------------*/
void
display_maze(void)
{
	int i;

	printf("MAZE:\n");
	for ( i = 0; i < NROWS; i++ )
	{
		printf("%.*s\n", MCOLS, maze[i]);
	}
	printf("\n");

	return;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function find_path                                             */
/*--------------------                                            */
/* Maze in cikis icin uygun olan yolunu bulup isaretler.          */
/*----------------------------------------------------------------*/
int
find_path(int x, int y)
{
	/* x,y labirentin disinda ise FALSE dondur. */
	if ( x < 0 || x > MCOLS - 1 || y < 0 || y > NROWS - 1 )
	{ 
	    return FALSE;
    }
	/* x,y Finishe geldiyse TRUE dondur. */
	if ( maze[y][x] == 'F' )
	{
	    return TRUE;
    }
	/* x,y kapali ise FALSE dondur. */
	if ( maze[y][x] != '.' && maze[y][x] != 'S' )
	{
	    return FALSE;
    }
	/* x,y koordinatlarinin gittigi yolu isaretle */
	maze[y][x] = '+';

	/* Eger x,y koordinatlarinin kuzeyi acik yani TRUE ise, return TRUE. */
	if ( find_path(x, y - 1) == TRUE ) 
	{
	    return TRUE;
    }
	/* Eger x,y koordinatlarinin dogu yonu acik yani TRUE ise, return TRUE. */
	if ( find_path(x + 1, y) == TRUE )
	{
	    return TRUE;
    }
	/* Eger x,y koordinatlarinin guneyi acik yani TRUE ise, return TRUE.*/
	if ( find_path(x, y + 1) == TRUE )
	{
	    return TRUE;
    }
	/* Eger x,y koordinatlarinin bati yonu acik yani TRUE ise, return TRUE.*/
	if ( find_path(x - 1, y) == TRUE ) 
	{
	    return TRUE;
    }
	/* Hicbiri degilse yol kapali isaretle.*/
	maze[y][x] = 'x';

	return FALSE;
}
/*################################################################*/
/*                  End of HW06_101044044_part2.c                 */
/*################################################################*/
