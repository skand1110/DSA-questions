//Approach:
/*
A step array is an array of integers where each element has a difference of at most k with its neighbor. 
Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.

-> A Simple Approach is to traverse the given array one by one and compare every element with the given element ‘x’. 
   If matches, then return index.
-> The above solution can be Optimized using the fact that the difference between all adjacent elements is at most k. 
-> The idea is to start comparing from the leftmost element and find the difference between the current array element and x. 
-> Let this difference be ‘diff’. From the given property of the array, we always know that x must be at least ‘diff/k’ away, 
   so instead of searching one by one, we jump ‘diff/k’. 
*/
//time complexity: O(n)
//space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
 
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x)/k);
    }
 
    cout << "number is not present!";
    return -1;
}