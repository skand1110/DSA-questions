//Approach 1: Sort the array since the range is of the form [low, high]
//Time Complexity: O(nlogn)
//----------------------------------------
//Approach 2: Dutch Flag Algo.
//Time Complexity: O(n); Space Complexity: O(1)

#include<iostream>
using namespace std;
 
// Partitions arr[0..n-1] around [lowVal..highVal]
void threeWayPartition(int arr[], int n,
                int lowVal, int highVal)
{
    // Initialize ext available positions for
    // smaller (than range) and greater elements
    int start = 0, end = n-1;
 
    // Traverse elements from left
    for (int i=0; i<=end;)
    {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        if (arr[i] < lowVal)
        {
          //if i and start are same in that case we can't swap
          //swap only if i is greater than start
          if(i==start)
          {
            start++;
            i++;
          }
          else
            swap(arr[i++], arr[start++]);
        }
 
        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);
 
        else
            i++;
    }
}