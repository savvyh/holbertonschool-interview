#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the sponge to draw
 */
void menger(int level) {
    if (level < 0) {
        return;
    }
    
     if (level == 0) {
       printf("#\n");
       return;
   }
    
    int size = pow(3, level);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i / (size / 3)) % 3 == 1 && (j / (size / 3)) % 3 == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}