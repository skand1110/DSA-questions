//Approach: Sliding Window 
//TC: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Sliding Window Technique
// Here the size of sliding window will be the number of elements less than or equal to k.
    int minSwap(int arr[], int n, int k) {
            int i,j;
            int windowsize=0;
            for(i=0;i<n;i++)
            {
                if(arr[i]<=k)
                ++windowsize;
            }
            if(windowsize==0 || windowsize==n) return 0;
            int greaterelem=0,minswap=INT_MAX;
            i=0;
            j=0;
            while(j<n)
            {
                if(arr[j]>k)
                ++greaterelem;
                if(j-i+1<windowsize)
                ++j;
                else
                {
                    minswap=min(minswap,greaterelem);
                    if(arr[i]>k)
                    --greaterelem;
                    ++i;
                    ++j;
                }
            }
            return minswap;
        }
};
