#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * menger - Draw a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 *
 * Draws a 2D Menger Sponge with the specified level.
 * If the level is lower than 0, the function does nothing.
 * The function uses the math library to calculate the size of the sponge.
 */
void menger(int level);

#endif /* MENGER_H */
