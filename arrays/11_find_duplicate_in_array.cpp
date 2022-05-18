// Approach 1: Binary Search
// Time complexity: O(nlogn)
/*
-> Perform Binary Search on range 1 to n;
-> low = 1, high = nums.size() - 1;
-> While the value of high is greater than or equal to low.
calculate mid.
-> count elements <= to mid.
-> if count is less than equal to mid.
-> low = mid + 1 (binary search on right half)
else high = mid + 1 (binary search on left half)
-> Return low which will point to duplicate.
*/
#include<bits/stdc++.h>
using namespace std;
 // Using Binary search
    // TC: O(nlogn), SC: O(1)
    int binarySearchSolution(vector<int>& nums) {
        // The idea is that it is known that there is a duplicate, so 
        // we can use pigeon hole concept here. We do binary search on the search
        // space of [1:N], then count the number of elements <= middle. If the 
        // duplicate is on the left side, then count should be more than mid,
        // else it is on the right side. Initially search space is [1: N], then
        // each time narrow down the search space
        int left = 1, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            // count the number of elements smaller/ equal than middle element
            int c = 0;
            for(const int& el: nums)
                if(el <= mid)
                    ++c;
            
            if(c > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
//-----------------------------------------------------------------
// Approach 2: Brute force, traverse the array and find adjacent same elements
// Time complexity: O(logn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ind = 0;
		
		// sort the vector
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
			// if two consecutive elements are equal
			// you have find a duplicate
			// break the loop
            if(nums[i] == nums[i+1])
            {
                ind = nums[i];
                break;
            }
        }
        // return duplicate value
        return ind;
    }
};
//------------------------------------------------------------------
//Aproach 3: Floyd Hare and Tortoise Algo
/*
Time Complexity: O(n); Space Complexity: O(1)
Tortoise and Hare Algo:

Take two pointers (basically integers) namely, slow and fast. Initially both will point to first element
Increase slow by 1 and fast by two.
Step 2 will be done as follows: slow = nums[slow]; fast = nums[nums[fast]].
There will be one time when slow and fast will meet. They will meet in a cycle.
At step 4 we have to stop.
Now move fast to initial position i.e. fast = nums[0].
Now move both slow and fast by one position till both of them meet.
Step 7 increment will be done as follows: slow = nums[slow]; fast = nums[fast].
The node at which both slow and fast will meet will be the duplicate number.
Return slow or fast :).
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
//-----------------------------------------------
//Approach 4: Index/frequency storing method
// TC: O(N), SC: O(1)
class Solution {
public:
    /*
        Since the numbers are [1:N], so we use the array indices for storing the
        visited state of each number, only the duplicate will be visited twice.
        For each number we goto its index position and multiply by -1. In case
        of duplicate it will be multiplied twice and the number will be +ve.
    */
    int indexSolution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            
            // mark as visited
            nums[index] *= -1;
            // incase of duplicate, this will become +ve 
            if(nums[index] > 0)
                return abs(nums[i]);
        }    
        return -1;
    }
};