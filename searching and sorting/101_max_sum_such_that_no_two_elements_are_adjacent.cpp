//Given an array arr[] of positive numbers, the task is to find the maximum sum of a subsequence with the constraint 
//that no 2 numbers in the sequence should be adjacent in the array.
/*
Approach : Dynamic Programming 

each element has two choices. If one element is picked then its neighbours cannot be picked. 
Otherwise, its neighbours may be picked or may not be. 
So the maximum sum till ith index has two possibilities: the subsequence includes arr[i] or it does not include arr[i].
If arr[i] is included then the maximum sum depends on the maximum subsequence sum till (i-1)th element excluding arr[i-1].
Otherwise, the maximum sum is the same as the maximum subsequence sum till (i-1) where arr[i-1] may be included or excluded.

So we build a 2D dp[N][2] array where dp[i][0] stores maximum subsequence sum till ith index with arr[i] excluded 
and dp[i][1] stores the sum when arr[i] is included.
The values will be obtained by the following relations: dp[i][1] = dp[i-1][0] + arr[i] and dp[i][0] = max(dp[i-1][0], dp[i-1][1])

-> If the size of the array is 1, then the answer is arr[0].
-> Initialize the values of dp[0][0] = 0 and dp[0][1] = arr[0].
-> Iterate from i = 1 to N-1:

Return the maximum between dp[N-1][1] and dp[N-1][0] as answer.
*/
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the maximum sum
int findMaxSum(vector<int> arr, int N)
{
    // Declare dp array
    int dp[N][2];
    if (N == 1) {
        return arr[0];
    }
   
    // Initialize the values in dp array
    dp[0][0] = 0;
    dp[0][1] = arr[0];
   
    // Loop to find the maximum possible sum
    for (int i = 1; i < N; i++) {
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][0] = max(dp[i - 1][1],
                       dp[i - 1][0]);
    }
   
    // Return the maximum sum
    return max(dp[N - 1][0], dp[N - 1][1]);
}