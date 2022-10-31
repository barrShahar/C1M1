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
 * @file stats.h
 *
 * @brief First assigment to "Introduction to Embedded Systems Software and Development" course
 *
 * A simple C-Programming that calculates statistics on a set of numbers:
 *     -Maximum
 *     -Minimum
 *     -Mean
 *     -Median
 *
 *
 * @author Shahar Barr
 * @date 28.11.2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */


/**
 * @brief Functrion that print nicely inputes parameters
 *
 *  For some data this function gets a statistic input: minimum, maimum, mean and median
 *  and prints them
 *
 * @param min     : variable of type 'unsigned char'
 * @param max     : variable of type 'unsigned char'
 * @param mean    : variable of type 'unsigned char'
 * @param median  : variable of type 'unsigned char'
 */
void print_statistics(unsigned char min, unsigned char max,
                      unsigned char mean, unsigned char median);


/**
 * @brief printing array of type 'unsigned char'
 *
 *  This function receives a pointer to the beginning of an array of type unsigned char, the length of the array
 *  and print that to the screen
 *
 * @param array  : pointer to the beginning of an array of type 'unsigned char'
 * @param length : variable that indicates the length of the array
 *
 */
void print_array(unsigned char* array, unsigned int length);

/**
 * @brief find median of an array
 *
 *  This function receives a pointer to the beginning of an array of type unsigned char, sorting it,
 *  and return the middle value if the array size is odd.
 *  if the array size is even, it returns the mean of the two middle values
 *
 * @param array  : pointer to the beginning of an array of type 'unsigned char'
 * @param length : variable that indicates the length of the array
 *
 * @return 'unsiged char' value of the median
 */
unsigned char find_median(unsigned char* array, unsigned int length);

/**
 * @brief find mean of an array
 *
 *  This function receives a pointer to the beginning of an array of type unsigned char
 *  and sum the values of the array and divide them by the length of the array
 *  Warning: the summation might overflow for a very long array
 *
 * @param array  : pointer to the beginning of an array of type 'unsigned char'
 * @param length : variable that indicates the length of the array
 *
 * @return 'unsiged char' value of the array
 */
unsigned char find_mean(unsigned char* array, unsigned int length);

/**
 * @brief returns the array maximum value
 *
 *  Iterate on a given array and returns the maximum value
 *
 * @param array  : pointer to the beginning of an array of type 'unsigned char'
 * @param length : variable that indicates the length of the array
 *
 * @return the maximum variable in the array
 */
unsigned char find_maximum(unsigned char* array, unsigned int length);

/**
 * @brief returns the array minimum value
 *
 *  Iterate on a given array and returns the maximum value
 *
 * @param array  : pointer to the beginning of an array of type 'unsigned char'
 * @param length : variable that indicates the length of the array
 *
 * @return the minimum variable in the array
 */
unsigned char find_minimum(unsigned char* array, unsigned int length);

/**
 * @brief sort an array of type 'unsigned char'
 *
 *  passing the input arguments to a function that implements merge sort algorithm
 *
 * @param array  : pointer to the beginning of an array of type 'unsigned char'
 * @param length : variable that indicates the length of the array
 */
void sort_array(unsigned char* array, unsigned int length);

/**=====================    Helper functions     =========================================*/
/**
 * @brief merge sort algorithm
 *
 * Merge sort algorithm sorting an array by divide-and-conquer approach
 * The algorithm devied an array by two recursively and then merging
 * them via megre functoin.
 * Sorting the array from index 'l' to index 'r'
 *
 * @param array :  a pointer to an unsorted array of type char
 * @param l     : starting sorting index array of type unsigned int
 * @param r     : final sorting index array of  type unsined int
 */

void mergeSort(unsigned char* array,unsigned int l,unsigned int r);

/**
 * @brief helper function to mergeSort, merging between two sorted array
 *
 * merge function receive three indexes (l,q,r) and an array
 * array is sorted between indexes (l,q) and indexes (q,r)
 * the function returns a sorted array between indexes (l,r)
 *
 * @param array : pointer to the initial position of the array
 * @param l     : index of the first sorted array
 * @param q     : index of the seconed sorted array
 * @param r     : index of the final second array position
 *
 */
void merge(unsigned char* array,unsigned int l, unsigned int q, unsigned int r);

#endif /* __STATS_H__ */
