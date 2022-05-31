//Brute Force approach: using 3 for loops
//time complexity: O(n^3)

#include<bits/stdc++.h>
using namespace std;
 
int countTriplets(int arr[], int n, int sum)
{
    // Initialize result
    int ans = 0;
 
    // Fix the first element as A[i]
    for (int i = 0; i < n-2; i++)
    {
       // Fix the second element as A[j]
       for (int j = i+1; j < n-1; j++)
       {
           // Now look for the third number
           for (int k = j+1; k < n; k++)
               if (arr[i] + arr[j] + arr[k] < sum)
                   ans++;
       }
    }
 
    return ans;
}

/*
An Efficient Approach involves sorting the array first and then applying the meet in the middle approach 
to effectively count all the possible cases of triplets without going through all the triplets .

For meet in the middle part, we create two pointers, which take into consideration left index and right index respectively of the sorted array.
After that, we run a for loop and each element is considered where 
left index will be indicating the index next to element considered and right index will be indicating the last index of the array.

Then, we count the sum of triplet created as :
    sum = arr[ind]+arr[left_ind] + arr[right_ind] 
If sum is less than desired val ,then all the element lying between left and right index will have value less than the desired value. 
Hence, we can increase the resultant count by :
    cnt = cnt + (right_ind-left_ind) ;
Else if sum is greater than the required value, then we reduce the right index value by 1 to consider the next element in the sorted array 
    .i.e : right_ind = right_ind -1 ;

Sorting requires O(nlogn) time and meet in the middle part consists of a for loop and left & right pointer 
which iterates from 0 to n-1 index in the initial cases which gives the second part the time complexity of : O(n)*O(n) = O(n²).
*/

#include<bits/stdc++.h>
using namespace std;
 
int countTriplets(int arr[], int n, int sum)
{
    // Sort input array
    sort(arr, arr+n);
 
    // Initialize result
    int ans = 0;
 
    // Every iteration of loop counts triplet with
    // first element as arr[i].
    for (int i = 0; i < n - 2; i++)
    {
        // Initialize other two elements as corner elements
        // of subarray arr[j+1..k]
        int j = i + 1, k = n - 1;
 
        // Use Meet in the Middle concept
        while (j < k)
        {
            // If sum of current triplet is more or equal,
            // move right corner to look for smaller values
            if (arr[i] + arr[j] + arr[k] >= sum)
                k--;
 
            // Else move left corner
            else
            {
                // This is important. For current i and j, there
                // can be total k-j third elements.
                ans += (k - j);
                j++;
            }
        }
    }
    return ans;
}
 
