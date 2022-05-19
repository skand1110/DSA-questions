//Approach 1: Brute force, We can iterate over the array with two pointers, while we obtain all the subarrays sum
//Time Complexity: O(n^2); Space Complexity: O(1)
/*
A simple solution is to consider all subarrays one by one and check the sum of every subarray. 
We can run two loops: the outer loop picks a starting point i and the inner loop tries all subarrays starting from i
*/
#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum) 
{ 
    int curr_sum, i, j; 
  
    // Pick a starting point 
    for (i = 0; i < n; i++) { 
        curr_sum = arr[i]; 
  
        // try all subarrays starting with 'i' 
        for (j = i + 1; j <= n; j++) { 
            if (curr_sum == sum) { 
                cout << "Sum found between indexes "
                     << i << " and " << j - 1; 
                return 1; 
            } 
            if (curr_sum > sum || j == n) 
                break; 
            curr_sum = curr_sum + arr[j]; 
        } 
    } 
  
    cout << "No subarray found"; 
    return 0; 
} 

//---------------------------------------------------------
//Approach 2: Hashing
//Time Complexity: O(1); Space Complexity: O(n)
/*
The idea is to iterate through the array and for every element arr[i], 
calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]). 
If the current sum has been seen before, then there is a zero-sum array. 
Hashing is used to store the sum values so that we can quickly store sum and 
find out whether the current sum is seen before or not.
*/
// A C++ program to find if 
// there is a zero sum subarray
#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;

    // Traverse through array 
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += arr[i];

        // If prefix sum is 0 or 
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;

        sumSet.insert(sum);
    }
    return false;
}