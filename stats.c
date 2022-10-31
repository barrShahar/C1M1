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

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
    unsigned char min, max, mean, median;
    
  /* Statistics and Printing Functions Go Here */
    min = find_minimum(test, SIZE);
    max = find_maximum(test, SIZE);
    mean = find_mean(test, SIZE);
    median = find_median(test, SIZE);
    
    print_statistics(min, max, mean, median);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char min, unsigned char max,
                      unsigned char mean, unsigned char median){

    printf("*****************************************\n");
    printf("* Minimum value of the array is : %d\n",min);
    printf("* Maximum value of the array is : %d\n",max);
    printf("* Mean value of the array is    : %d\n",mean);
    printf("* Median value of the array is  : %d\n",median);
    printf("*****************************************\n");
}

void print_array(unsigned char* array, unsigned int length){
    printf("[");
    for (unsigned int i = 0; i < length - 1; ++i)
        printf("%d ", array[i]);
    printf("%d]\n", array[length-1]);
}

unsigned char find_median(unsigned char* array, unsigned int length){
    
    /* Copying the data from input array to c_arr (copy array) */
    unsigned char c_arr[length];
    for (unsigned int i = 0; i < length; ++i)
        c_arr[i] = array[i];
    
    /* Sorting the array */
    sort_array(c_arr, length);

    /* Returns the calculated mean */
    if (length % 2 == 0) // length is even
        return (c_arr[length/2] + c_arr[length/2-1])/2;
    return c_arr[length/2];
}

unsigned char find_mean(unsigned char* array, unsigned int length){
    
    /* Declaration of the summation variable */
    unsigned long sum = 0;
    
    for (unsigned int i = 0; i < length; ++i)
        sum += array[i];
    
    return (unsigned char) (sum/length);
}


unsigned char find_maximum(unsigned char* array, unsigned int length){
    
    /* Must initialize to values in set, not zero */
    unsigned char max = array[0];
    
    for (unsigned int i = 1; i < length; ++i)
        if (array[i] > max)
            max = array[i];
    
    return max;
}

unsigned char find_minimum(unsigned char* array, unsigned int length){
    
    /* Must initialize to values in set, not zero */
    unsigned char min = array[0];
    
    for (unsigned int i = 1; i < length; ++i)
        if (array[i] < min)
            min = array[i];
    
    return min;
}

void merge(unsigned char* array,unsigned int l, unsigned int q, unsigned int r){
    /* Create two temp sub arrays: */
    unsigned int n1, n2;
    n1 = q-l;
    n2 = r-q;
    unsigned char left_arr[n1];
    unsigned char right_arr[n2];
    
    /* Copy data to temp arrays */
    for (int i = 0; i < n1; ++i)
        left_arr[i] = array[i+l];
    
    for (int i = 0; i < n2; ++i)
        right_arr[i] = array[i+q];

    /* Merge the temp sub arrays back into array: */
    unsigned int l_i = 0, r_i = 0, i = l;
    while(l_i < n1 && r_i < n2)
    {
        if (left_arr[l_i] > right_arr[r_i]){
            array[i] = right_arr[r_i];
            r_i++;
        }
        else{
            array[i] = left_arr[l_i];
            l_i++;
        }
        i++;
    }
    
    /* Copy the remaining elements from one of the sub array into array */
    while (l_i < n1){
        array[i] = left_arr[l_i];
        l_i++;
        i++;
    }
    
    while (r_i < n2){
        array[i] = right_arr[r_i];
        r_i++;
        i++;
    }
}

void merge_sort(unsigned char* array,unsigned int l,unsigned int r){

    if (r-l < 2)
        return;
    unsigned int q = (l+r)/2;
    merge_sort(array,l,q);
    merge_sort(array, q, r);
    merge(array,l,q,r);
}

void sort_array(unsigned char* array, unsigned int length){
    merge_sort(array,0,length);
}
