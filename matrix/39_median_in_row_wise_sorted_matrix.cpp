//Approach 1:
//store all the elements of the given matrix in an array of size r*c. 
//Then sort the array and find the median element in O(r*clog(r*c))
//Space Complexity: O(r*c)

//----------------------------------------------------------------
//Approach 2:
/*
refer to kth smallest or largest element search in an unsorted array question
here k is equal to n/2
*/
//Time Complexity: O(r*c); Space Complexity: O(r*c)

//----------------------------------------------------------------
//Approach 3: Using binary search
/*
Algorithm:  
1. First, we find the minimum and maximum elements in the matrix. 
The minimum element can be easily found by comparing the first element of each row, 
and similarly, the maximum element can be found by comparing the last element of each row.
2. Then we use binary search on our range of numbers from minimum to maximum, 
we find the mid of the min and max and get a count of numbers less than or equal to our mid. 
And accordingly change the min or max.
3. For a number to be median, there should be (r*c)/2 numbers smaller than that number. 
So for every number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, 
if it is less than the required count, the median must be greater than the selected number, 
else the median must be less than or equal to the selected number.
*/

// C++ program to find median of a matrix
// sorted row wise
#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 100;
 
// function to find median in the matrix
int binaryMedian(int m[][MAX], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
 
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
 
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
 
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
 