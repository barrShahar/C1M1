/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief First assigment to "Introduction to Embedded Systems Software and Development" course
 *
 * A simple C-Programming that calculates statistics on a set of numbers:
 *     -Maximum
 *     -Minimum
 *     -Mean
 *     -Median
 *
 * @author Shahar Barr
 * @date 28.11.2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

    
  /* Statistics and Printing Functions Go Here */


  return 0;
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char min, unsigned char max,
                      unsigned char mean, unsigned char median){
  return;
}

void print_array(unsigned char* array, unsigned int length){
  return;
}

unsigned char find_median(unsigned char* array, unsigned int length){
    
  return 0;
}

unsigned char find_mean(unsigned char* array, unsigned int length){

  return 0;
}


unsigned char find_maximum(unsigned char* array, unsigned int length){

  return 0;
}

unsigned char find_minimum(unsigned char* array, unsigned int length){
    
  return 0;
}

void merge(unsigned char* array,unsigned int l, unsigned int q, unsigned int r){
  return;
}

void mergeSort(unsigned char* array,unsigned int l,unsigned int r){
  return;
}

void sort_array(unsigned char* array, unsigned int length){
    mergeSort(array,0,length);
}
