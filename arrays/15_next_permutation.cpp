/*
Algorithm:
step 1: Linearly traverse given array from the end and find a number 
that is greater than its adjacent nums[i] > nums[i-1]. 
Store the index of smaller number in breakPoint variable. 
If there is no such element, reverse entire array and return.

step 2: Linearly traverse from the end and this time 
find a number larger than nums[breakPoint]. Let's call it nums[i].

step 3: Swap nums[i] and nums[breakPoint].

step 4: Reverse the array from index breakPoint + 1 to nums.size().
*/

#include<bits/stdc++.h>
using namespace std;

// find next permutation
void nextPermutation(vector<int> &nums)
{
    // initialize variable:
    int breakPoint = -1;

    // find a breakpoint:
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            breakPoint = i - 1;
            break;
        }
    }

    // if no breakpoint
    if (breakPoint < 0)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // if found a breakpoint
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > nums[breakPoint])
        {
            swap(nums[breakPoint], nums[i]);
            reverse(nums.begin() + breakPoint + 1, nums.end());
            break;
        }
    }
}