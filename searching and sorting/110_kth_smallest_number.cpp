//Approach: using binary search
//Time complexity: O((mx-mn)(log(mx-mn))), where mn be minimum and mx be maximum. Auxiliary Space: O(1)
/*
The idea to solve this problem is that the Kth smallest element would be the element at the kth position if the array was sorted in increasing order. Using this logic, 
we use binary search to predict the index of an element as if the array was sorted but without actually sorting the array. 
Example: {1, 4, 5, 3, 19, 3} & k = 2 
Here we find that element which has exactly k + 1 elements (including itself) lesser to it. Hence, the kth smallest element would be 3 in this case. 
Follow the steps below to implement the above idea:

Find low and high that is the range where our answer can lie. 
 Apply Binary Search on this range. 
 If the selected element which would be mid has less than k elements lesser to it then increase the number that is low = mid + 1.
Otherwise, Decrement the number and try to find a better answer (to understand this please try running on an array containing duplicates).
The Binary Search will end when only one element remains in the answer space which would be our answer.
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int count(vector <int>& nums, int& mid)
{//function to calculate number of elements less than equal to mid
        int cnt = 0;
         
        for(int i = 0; i < nums.size(); i++)
           if(nums[i] <= mid)
              cnt++;
         
        return cnt;
}
     
 
int kthSmallest(vector <int> nums, int& k)
{
        int low = INT_MAX;
        int high = INT_MIN;
        //calculate minimum and maximum the array.
        for(int i = 0; i < nums.size(); i++)
        {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }
        //Our answer range lies between minimum and maximum element of the array on which Binary Search is Applied
        while(low < high)
        {
            int mid = low + (high - low) / 2;
           /*if the count of number of elements in the array less than equal to mid is less than k
             then increase the number. Otherwise decrement the number and try to find a better answer.
           */
            if(count(nums, mid) < k)
               low = mid + 1;
                
            else
                high = mid;
        }
         
        return low;
}
 
int main()
{
 
    vector <int> nums{1, 4, 5, 3, 19, 3};
    int k = 3;
    cout << "K'th smallest element is " << kthSmallest(nums, k);
    return 0;
}
