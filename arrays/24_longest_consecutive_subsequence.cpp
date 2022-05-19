//Approach1: Simple array
//Time Complexity: O(n); Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class solution{
public:
int findLongestConseqSubseq(int arr[], int N)
   {
    int temp[100000]={0};
        int maxIndex=0;
        for(int i=0;i<N;i++){
            temp[arr[i]]=1;
            maxIndex=max(maxIndex, arr[i]);
        }
        int maxCount=0; int count=0;
        for(int i=1;i<=maxIndex;i++){
            if(temp[i])
                count++;
            else
                count=0;
            maxCount=max(maxCount, count);
        }
        return maxCount;
    }
};

//------------------------------------------------
//Approach 2: using hash map
//Time Complexity: O(n); Space Complexity: O(n)
/*
Create an empty hash.
Insert all array elements to hash.
Do following for every element arr[i]
Check if this element is the starting point of a subsequence. 
To check this, simply look for arr[i] - 1 in the hash, if not found, then this is the first element a subsequence.
If this element is the first element, then count the number of elements in the consecutive starting with this element. 
Iterate from arr[i] + 1 till the last element that can be found.
If the count is more than the previous longest subsequence found, then update this.
*/

// C++ program to find longest
// contiguous subsequence
#include <bits/stdc++.h>
using namespace std;

// Returns length of the longest
// contiguous subsequence
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;

    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

//--------------------------------------------
//Approach 3: Priority Queue
//TC: O(nlogn)