/* CMPT 332 Fall 2018
 * Lab 3 - sample program
 * Name: Kai Langen
 * NSID: protected
 * Student Number: protected
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int i, x, y, arrSize = 50, *iPtr1, *iPtr2;
  /*
   * Initialize array with numbers.
   */
  int *numbers = malloc(sizeof(int) * arrSize);
  numbers[0] = 0;

  for(i = 1; i < arrSize; i++)
    numbers[i] = i + numbers[i - 1] + 1;


  /*
   * Weird for-loop with lots of effects
   */
  for(i = 0; i < arrSize; i++) {
    x = numbers[i];
    iPtr1 = &numbers[x % arrSize];
    y = (*iPtr1) * 2;
    iPtr2 = &numbers[(y % arrSize) + 20];
    *iPtr2 = x;
  }

  free(numbers);
  return 0;
}
