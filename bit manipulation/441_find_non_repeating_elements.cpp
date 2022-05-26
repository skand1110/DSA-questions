/*
Given an array in which all numbers except two are repeated once. 
(i.e. we have 2n+2 numbers and n numbers are occurring twice and remaining two have occurred once).
*/
//Approach 1: sort the elements and if two consecutive elements are not same then they can be one or both of the non-repeating ones
//--------------------------
//Approach 2:
//since the section is bit manipulation, we'll focus on approach 2 i.e. XOR implementation

#include <bits/stdc++.h>
using namespace std;
 
/* This function sets the values of
*x and *y to non-repeating elements
in an array arr[] of size n*/
void get2NonRepeatingNos(int arr[], int n, int* x, int* y)
{
    /* Will hold Xor of all elements */
    int Xor = arr[0];
 
    /* Will have only single set bit of Xor */
    int set_bit_no;
    int i;
    *x = 0;
    *y = 0;
 
    /* Get the Xor of all elements */
    for (i = 1; i < n; i++)
        Xor ^= arr[i];
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = Xor & ~(Xor - 1);
 
    /* Now divide elements in two sets by
    comparing rightmost set bit of Xor with bit
    at same position in each element. */
    for (i = 0; i < n; i++) {
 
        /*Xor of first set */
        if (arr[i] & set_bit_no)
            *x = *x ^ arr[i];
        /*Xor of second set*/
        else {
            *y = *y ^ arr[i];
        }
    }
}
 
