/*################################################################*/
/* HW01_101044044.c                                               */
/* ----------------------                                         */
/* Created on 21.02.2013 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* This program calculates the perimeter and the area of a        */
/* rectangular.Take the edges of the rectangular from the user    */
/* and outputs the perimeter and the area.                        */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>

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
    int edge1,   
        edge2,
        perimeter,
        area;
    
    /* Take the edges of the rectangular from the user */
    printf("Enter the edges of the rectangular:\n");
    printf("Note: Dont use a comma.\n");
    scanf("%d%d",&edge1,&edge2);
    
    /* Calculate perimeter */
    perimeter = 2 * (edge1 + edge2);
    
    /* Calculate rectangular area */
    area = (edge1 * edge2);
    
    /* Prints the screen calculate and perimeter */
    printf("Rectangular perimeter is: %4d\n",perimeter);
    printf("Rectangular area is: %9d\n",area);

    return 0;
}
/*################################################################*/
/*                  End of HW01_101044044.c                       */
/*################################################################*/
