//Approach 1: Using three pointers, three for loops
//Time Complexity: O(n^3) Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

bool tripletSum(int A[], int n, int X){
    for(int i=0; i<n-2; i++){
        for(int j=0; j<n-1; j++){
            for(int k=0; k<n; k++){
                if(A[i]+A[j]+A[k]==X){
                    return true;
                }
            }
        }
    }
    return false;
}
//-----------------------------------------------------
//Approach 2: Sorting and then using two pointers
//Time complexity: O(n^2) Space Complexity: O(1)

bool find3Numbers(int A[], int n, int X){
    sort(A,A+n);
            for(int i=0;i<n;i++)
            {
            int right=n-1,left=i+1;
            while(left<right)
            {
                if(A[i]+A[right]+A[left]==X)
                {
                    return true;
                }
                else if(A[i]+A[right]+A[left]>X)
                {
                    right--;
                }
                else if(A[i]+A[right]+A[left]<X)
                {
                    left++;
                }
                
        }

    }
    return false;
}
//---------------------------------------------------------------
//Approach 3: Hashing
//Time Complexity: O(n^2); Space Complexity: O(n)
/*
This approach uses extra space but is simpler than the two-pointers approach. 
Run two loops outer loop from start to end and inner loop from i+1 to end. 
Create a hashmap or set to store the elements in between i+1 to j-1. 
So if the given sum is x, check if there is a number in the set which is equal to x - arr[i] - arr[j]. 
If yes print the triplet. 
 
Algorithm: 
-> Traverse the array from start to end. (loop counter i)
-> Create a HashMap or set to store unique pairs.
-> Run another loop from i+1 to end of the array. (loop counter j)
-> If there is an element in the set which is equal to x- arr[i] - arr[j], then print the triplet (arr[i], arr[j], x-arr[i]-arr[j]) and break
-> Insert the jth element in the set.
*/

// C++ program to find a triplet using Hashing
#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++) 
    {

        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++) 
        {
            if (s.find(curr_sum - A[j]) != s.end()) 
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }

    // If we reach here, then no triplet was found
    return false;
}